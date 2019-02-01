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