#include "ViewerWindow.h"

ViewerWindow::ViewerWindow(const char* title, int width, int height)
{
	m_Title = title;
	m_Width = width;
	m_Height = height;
}

bool ViewerWindow::Init()
{
	if (!glfwInit())
	{
		std::cout << "Error initializing GLFW" << std::endl;
		return false;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	
	window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);

	if (window == NULL)
	{
		std::cout << "Error Creating GLFW Window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error initializing GLEW" << std::endl;
		glfwTerminate();
		return false;
	}

	return 1;
}