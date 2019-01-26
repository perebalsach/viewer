#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"
#include "ViewerWindow.h"


int main()
{
	ViewerWindow viewWidnow("Viewer", 800, 600);

	if (!viewWidnow.Init())
	{
		std::cout << "Error creating the window. See details below" << std::endl;
		return -1;
	}

	//glfwSetKeyCallback(viewWidnow.window, viewWidnow.glfw_onKey);

	// Main loop
	while (!glfwWindowShouldClose(viewWidnow.window))
	{
		glfwPollEvents();
		
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(viewWidnow.window);
	}

	glfwTerminate();
	return 0;
}