#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "ViewerWindow.h"
#include "Mesh.h"
#include "Shader.h"
#include "Font.h"



int main()
{
	ViewerWindow viewWidnow("Viewer", 800, 600, false);
	Font font;
	Mesh mesh;

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
	Shader shader;
	shader.loadShaders("content/shaders/unlit.vert", "content/shaders/unlit.frag");

	// Main loop
	while (!glfwWindowShouldClose(viewWidnow.getWindow()))
	{
		glfwPollEvents();
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		shader.use();

		GLfloat time = glfwGetTime();
		GLfloat blueColor = (sin(time)/ 2) + 0.5;
		glm::vec2 pos;
		pos.x = sin(time) * 0.5;
		pos.y = cos(time) * 0.5;
		

		shader.setUnifrom("posOffset", pos);
		shader.setUnifrom("vertColor", glm::vec4(0.1, 0.2, blueColor, 1.0));

		mesh.draw();

		viewWidnow.shoowFPS();
		glfwSwapBuffers(viewWidnow.getWindow());
	}

	mesh.clean();

	glfwTerminate();
	return 0;
}
