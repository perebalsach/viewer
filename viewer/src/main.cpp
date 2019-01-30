#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "ViewerWindow.h"
#include "Font.h"


int main()
{
	ViewerWindow viewWidnow("Viewer", 800, 600, false);
	Font font;

	
	GLfloat vertices[] =
	{
		0.0f,	 0.5f,	0.0f,
		0.5f,	-0.5f,	0.0f,
	   -0.5f,	-0.5f,	0.0f
	};

	GLuint vbo, vao;

	glGenBuffers(1,&vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	// glVertexAttribPointer(0, sizeof(vertices),  );

	if (!font.Load("content/fonts/pacifico.ttf"))
	{
		return 0;
	}

	if (!viewWidnow.Init())
	{
		std::cout << "Error creating the window. See details below" << std::endl;
		return -1;
	}

	glfwSetKeyCallback(viewWidnow.getWindow(), viewWidnow.glfwOnKey);

	// Main loop
	while (!glfwWindowShouldClose(viewWidnow.getWindow()))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		viewWidnow.shoowFPS();

		glfwSwapBuffers(viewWidnow.getWindow());
	}

	glfwTerminate();
	return 0;
}
