#pragma once
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Mesh
{
public:
	Mesh();
	bool load();
	GLuint loadShaders(const GLchar* vertexShaderSrc, const GLchar* fragmentShaderSrc);
	void draw();
	void clean();

	GLuint vbo, vao;
	GLuint shaderProgram;
private:

};

