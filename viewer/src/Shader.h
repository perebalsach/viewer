#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H


#include "GL/glew.h"
#include <string>

class Shader
{
public:
	Shader();
	~Shader();
	enum ShaderType
	{
		VERTEX, 
		FRAGMENT, 
		PROGRAM
	};

	bool loadShaders(const char* vsFilename, const char* fsFilename);
	void use();

private:

	std::string fileToString(const std::string& filename);
	void checkForCompileErrors(GLuint shader, ShaderType type);

	GLuint mHandle; 

};

#endif // !SHADER_PROGRAM_H


