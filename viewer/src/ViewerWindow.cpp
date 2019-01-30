#include "ViewerWindow.h"
#include <sstream>

ViewerWindow::ViewerWindow(const char* title, int width, int height, bool fullscreen)
{
	m_Title = title;
	m_Width = width;
	m_Height = height;
	m_fullscreen = fullscreen;
}

bool ViewerWindow::Init()
{
	// Inits GLFW
	if (!glfwInit())
	{
		std::cout << "Error initializing GLFW" << std::endl;
		return false;
	}

	if (m_fullscreen)
	{
		GLFWmonitor* monitor = glfwGetPrimaryMonitor();
		const GLFWvidmode* vidMode = glfwGetVideoMode(monitor);
		if (vidMode != NULL)
		{
			this->m_window = glfwCreateWindow(vidMode->width, vidMode->height, m_Title, monitor, NULL );
		}
	}
	else
	{
		this->m_window = glfwCreateWindow(m_Width, m_Height, m_Title, NULL, NULL);
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	

	if (m_window == NULL)
	{
		std::cout << "Error Creating GLFW Window" << std::endl;
		glfwTerminate();
		return false;
	}

	glfwMakeContextCurrent(m_window);

	glewExperimental = GL_TRUE;

	if (glewInit() != GLEW_OK)
	{
		std::cout << "Error initializing GLEW" << std::endl;
		glfwTerminate();
		return false;
	}

	shoowFPS();

	glClearColor(0.5f, 0.5f, 0.5f, 1.0f);

	return 1;
}

GLFWwindow* ViewerWindow::getWindow()
{
	return m_window;
}

void ViewerWindow::close()
{
	glfwSetWindowShouldClose(m_window, GL_TRUE);
}

void ViewerWindow::glfwOnKey(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
}

void ViewerWindow::shoowFPS()
{
	static double previousSeconds = 0.0;
	static int frameCount = 0;
	double elapsedSeconds;
	double currentSeconds = glfwGetTime();

	elapsedSeconds = currentSeconds - previousSeconds;

	if (elapsedSeconds > 0.25)
	{
		previousSeconds = currentSeconds;
		double fps = (double)frameCount / elapsedSeconds;
		double msPerSecond = 1000.0 / fps;
		
		std::ostringstream outs;
		outs.precision(3);
		outs << std::fixed
			<< m_Title << "   "
			<< "FPS: " << fps << "   "
			<< "Frame time: " << msPerSecond << " (ms)";
		glfwSetWindowTitle(m_window, outs.str().c_str());
		
		frameCount = 0;
	}

	frameCount++;
}