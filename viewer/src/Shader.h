#pragma once
#include <iostream>
#include <fstream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Shader
{
public:
	Shader();
	const GLchar* loadFromFile(const GLchar* filename);

private:

};



