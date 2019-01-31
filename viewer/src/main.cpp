#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "ViewerWindow.h"
#include "Mesh.h"
#include "Shader.h"
#include "Font.h"


const GLchar* vertexShaderSrc =
"#version 330 core\n"
"layout (location = 0) in vec3 pos;"
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
	Font font;
	Mesh mesh;
	Shader shader;

	// ------------- Fonts ------------------------------
	if (!font.Load("content/fonts/pacifico.ttf"))
	{
		return 0;
	}

	// ------------- Window initialitzation -------------
	if (!viewWidnow.Init())
	{
		std::cout << "Error creating the window. See details below" << std::endl;
		return -1;
	}
	
	// ------------- Window events initialitzation -------------
	glfwSetKeyCallback(viewWidnow.getWindow(), viewWidnow.glfwOnKey);

	// ------------- Mesh loading -------------------------------
	if (!mesh.load())
	{
		std::cout << "Error loading the mesh" << std::endl;
		return -1;
	}

	// ------------- Shader loading ------------------------------
	// shader.loadFromFile("content/shaders/unlit.vs");
	shader.loadFromFile("content/shaders/unlit.vs");
	// mesh.loadShaders( ,fragmentShaderSrc);
	// mesh.loadShaders(vertexShaderSrc, fragmentShaderSrc);

	// Main loop
	while (!glfwWindowShouldClose(viewWidnow.getWindow()))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		mesh.draw();

		viewWidnow.shoowFPS();
		glfwSwapBuffers(viewWidnow.getWindow());
	}

	mesh.clean();

	glfwTerminate();
	return 0;
}
