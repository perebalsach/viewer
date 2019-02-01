#include <iostream>
#include <string>
#include "Shader.h"

Shader::Shader()
{
}

bool Shader::loadShaders(const char* vsFilename, const char* fsFilename)
{
	std::ifstream shaderFile;

	std::ifstream file(vsFilename);
	
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			// using printf() in all tests for consistency
			std::cout << line.c_str() << std::endl;
			// printf("%s", line.c_str());
		}
		file.close();
	}
	return true;
}
