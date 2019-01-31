#include <iostream>
#include <string>
#include "Shader.h"

Shader::Shader()
{
}

const GLchar* Shader::loadFromFile(const GLchar* filename)
{
	std::ifstream shaderFile;
	const GLchar* vertexShaderSrc = "sdsdsdsd";

	std::ifstream file(filename);
	
	if (file.is_open()) {
		std::string line;
		while (std::getline(file, line)) {
			// using printf() in all tests for consistency
			printf("%s", line.c_str());
		}
		file.close();
	}
	return vertexShaderSrc;
}
