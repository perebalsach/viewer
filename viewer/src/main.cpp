#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "ViewerWindow.h"
// #include "Font.h"


const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location 0) in vec3 pos;"
"void main()"
"{"
"	gl_Position = vec4(pos.x, pos.y, pos.z, 1.0);"
"}";

const GLchar* fragmentShaderSrc =
"#version 330 core\n"
"out vec4 frag_color;"
"void main()"
"{"
"	frag_color = vec4(0.5f, 0.2f, 0.2f, 1.0f);"
"}";


int main()
{
	ViewerWindow viewWidnow("Viewer", 800, 600, false);
	//Font font;

	// ------------ MESH GENERATION
	GLfloat vertices[] =
	{
		0.0f,	 0.5f,	0.0f,
		0.5f,	-0.5f,	0.0f,
	   -0.5f,	-0.5f,	0.0f
	};

	GLuint vbo, vao;

	/*if (!font.Load("content/fonts/pacifico.ttf"))
	{
		return 0;
	}*/

	if (!viewWidnow.Init())
	{
		std::cout << "Error creating the window. See details below" << std::endl;
		return -1;
	}

	glfwSetKeyCallback(viewWidnow.getWindow(), viewWidnow.glfwOnKey);

	// ---------------------------------------------------------------------------------------------------
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray(0);

	// ----------- SHADER
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
	}

	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vs);
	glAttachShader(shaderProgram, fs);
	glLinkProgram(shaderProgram);

	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &result);
	if (!result)
	{
		glGetProgramInfoLog(shaderProgram, sizeof(infoLog), NULL, infoLog);
		std::cout << "ERROR::SHADER LINKER: Can not be linked! " << infoLog << std::endl;
	}

	glDeleteShader(vs);
	glDeleteShader(fs);
	// ---------------------------------------------------------------------------------------------------



	// Main loop
	while (!glfwWindowShouldClose(viewWidnow.getWindow()))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		// -------------------------------------------
		glUseProgram(shaderProgram);

		glBindVertexArray(vao);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		// -------------------------------------------

		viewWidnow.shoowFPS();

		glfwSwapBuffers(viewWidnow.getWindow());
	}

	glDeleteProgram(shaderProgram);
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(1, &vbo);

	glfwTerminate();
	return 0;
}
