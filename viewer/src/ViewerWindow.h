#pragma once
#include <iostream>

#define GLEW_STATIC
#include "GL/glew.h"
#include "GLFW/glfw3.h"

class ViewerWindow
{
public:
	ViewerWindow(const char* title, int width, int height);
	bool Init();

	GLFWwindow* window;

private:
	const char* m_Title;
	int m_Width;
	int m_Height;
};