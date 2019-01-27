#pragma once
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class ViewerWindow
{
public:
	ViewerWindow(const char* title, int width, int height, bool fullscreen=false);
	
	bool Init();
	GLFWwindow* getWindow();
	void close();
	static void glfwOnKey(GLFWwindow* window, int key, int scancode, int action, int mode);
	void shoowFPS();

private:
	const char* m_Title;
	int m_Width;
	int m_Height;
	bool m_fullscreen;

	GLFWwindow* m_window;
};