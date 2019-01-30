#include "Mesh.h"
#include <iostream>


Mesh::Mesh()
{

}


bool Mesh::load()
{
	GLfloat vertices[] =
	{
		0.0f,	 0.5f,	0.0f,
		0.5f,	-0.5f,	0.0f,
	   -0.5f,	-0.5f,	0.0f
	};

	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	return true;
}

GLuint Mesh::loadShaders(const GLchar* vertexShaderSrc, const GLchar* fragmentShaderSrc)
{
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertexShaderSrc, NULL);
	glCompileShader(vs);

	// Error checking shaders
	GLint result;
	GLchar infoLog[512];

	glGetShaderiv(vs, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(vs, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::VERTEX SHADER: Can not be compiled! " << infoLog << std::endl;
	}

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragmentShaderSrc, NULL);
	glCompileShader(fs);

	glGetShaderiv(fs, GL_COMPILE_STATUS, &result);
	if (!result)
	{
		glGetShaderInfoLog(fs, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::FRAGMENT SHADER: Can not be compiled! " << infoLog << std::endl;
		return -1;
	}

	shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER LINKER: Can not be linked! " << infoLog << std::endl;
		return -1;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);
}

void Mesh::draw()
{
	glUseProgram(shaderProgram);

	glBindVertexArray(vao);
	glDrawArrays(GL_TRIANGLES, 0, 3);
	glBindVertexArray(0);
}

void Mesh::clean()
{
	glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);
}