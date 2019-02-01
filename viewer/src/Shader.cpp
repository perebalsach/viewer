#include "Shader.h"
#include <fstream>
#include <iostream>
#include <sstream>


Shader::Shader()
	: mHandle(0)
{
	
}

Shader::~Shader()
{
	glDeleteProgram(mHandle);
}

bool Shader::loadShaders(const char* vsFilename, const char* fsFilename)
{
	std::string vsStirng = fileToString(vsFilename);
	std::string fsStirng = fileToString(fsFilename);

	const GLchar* vsSourcePtr = vsStirng.c_str();
	const GLchar* fsSourcePtr = fsStirng.c_str();


	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);

	glShaderSource(vs, 1, &vsSourcePtr, NULL);
	glShaderSource(fs, 1, &fsSourcePtr, NULL);

	glCompileShader(vs);
	checkForCompileErrors(vs, VERTEX);
	glCompileShader(fs);
	checkForCompileErrors(fs, FRAGMENT);

	mHandle = glCreateProgram();

	glAttachShader(mHandle, vs);
	glAttachShader(mHandle, fs);
	glLinkProgram(mHandle);
	checkForCompileErrors(mHandle, PROGRAM);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return true;
}

void Shader::use()
{
	if (mHandle > 0)
	{
		glUseProgram(mHandle);
	}
}

std::string Shader::fileToString(const std::string& filename)
{
	std::stringstream ss;
	std::ifstream file;

	try
	{
		file.open(filename, std::ios::in);
		if (!file.fail())
		{
			// Read form file and save the contents
			ss << file.rdbuf();
		}

		file.close();
	}
	catch (std::exception ex)
	{
		std::cerr << "Error reading the shader file!" << std::endl;
	}

	return ss.str();
}

void Shader::checkForCompileErrors(GLuint shader, ShaderType type)
{
	int status = 0;

	if (type == PROGRAM)
	{
		glGetProgramiv(mHandle, GL_LINK_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint length = 0;
			glGetProgramiv(mHandle, GL_INFO_LOG_LENGTH, &length);

			std::string errorLog(length, ' ');
			glGetProgramInfoLog(mHandle, length, &length, &errorLog[0]);
			std::cerr << "Error! Program failed to link" << errorLog << std::endl;
		}
	}
	else // VERTEX or FRAGMENT compiling
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE)
		{
			GLint length = 0;
			glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);

			std::string errorLog(length, ' ');
			glGetShaderInfoLog(shader, length, &length, &errorLog[0]);
			std::cerr << "Error! Shader failed to compile" << errorLog << std::endl;
		}
	}
}
