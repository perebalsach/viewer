#include <iostream>
#include "Font.h"

Font::Font()
{
	FT_Library  library;   /* handle to library     */
	FT_Face     face;      /* handle to face object */
	FT_Error    error;
	const char* filename = "content/fonts/pacifico.ttf";

	if (FT_Init_FreeType(&library))
	{
		throw std::runtime_error("FT_Init_FreeType failed");
	}
	FT_New_Face(library, "content/fonts/pacifico.ttf", 0, &face);
	// error = FT_New_Face(library, filename, 0, &face);
}
