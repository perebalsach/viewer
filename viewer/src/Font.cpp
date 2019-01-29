#include <iostream>
#include "Font.h"
#include <fstream>

Font::Font()
{
	if (FT_Init_FreeType(&m_library))
	{
		std::cout << "FT_Init_FreeType failed" << std::endl;
	}
}

bool Font::Load(const char* path)
{
	if (FT_New_Face(m_library, path, 0, &m_face))
	{
		std::cout << "ERROR::FREETYPE: Failed loading the font file" << std::endl;
		return false;
	}

	FT_Set_Pixel_Sizes(m_face, 0, 48);

	if (FT_Load_Char(m_face, 'X', FT_LOAD_RENDER))
	{
		std::cout << "ERROR::FREETYPE: Failed to load the glyph" << std::endl;
		return false;
	}

	std::cout << "Font loaded succesfully" << std::endl;
	
	
	return true;
}