#pragma once

// Std. Includes
#include <iostream>
#include <map>
#include <string>

#include "ft2build.h"
#include FT_FREETYPE_H

// GLEW / GLFW
#include "GL/glew.h"
#include "GLFW/glfw3.h"

#include "glm/glm.hpp"

class Font
{
public:
	Font();
	bool Load(const char* path);
	
	struct Character
	{
		GLuint Texture2D;
		glm::ivec2 Size;
		glm::ivec2 Bearing;
		GLuint Advance;
	};

private:
	const char* m_filename;
	FT_Library  m_library;   /* handle to library     */
	FT_Face     m_face;      /* handle to face object */
	FT_Error    m_error;

};

