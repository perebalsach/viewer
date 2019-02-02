#ifndef SHADER_PROGRAM_H
#define SHADER_PROGRAM_H

#include "GL/glew.h"
#include <string>
#include <glm/glm.hpp>
#include <map>

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

	void setUnifrom(const GLchar* name, const glm::vec2& v);
	void setUnifrom(const GLchar* name, const glm::vec3& v);
	void setUnifrom(const GLchar* name, const glm::vec4& v);

private:

	std::string fileToString(const std::string& filename);
	void checkForCompileErrors(GLuint shader, ShaderType type);
	GLuint getUniformLocation(const GLchar* name);

	GLuint mHandle; 
	std::map<std::string, GLint> mUniformLocations;
};

#endif // !SHADER_PROGRAM_H


