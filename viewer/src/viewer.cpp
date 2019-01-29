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
		
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		
		viewWidnow.shoowFPS();

		glfwSwapBuffers(viewWidnow.getWindow());
	}

	glfwTerminate();
	return 0;
}
