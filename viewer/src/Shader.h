#pragma once
#include <iostream>
#include <fstream>

#include "GL/glew.h"
#include "GLFW/glfw3.h"

class Shader
{
public:
	Shader();
	bool loadShaders(const char* vsFilename, const char* fsFilename);

private:

};



