#pragma once
#include <string>

namespace Logger {
	/// <summary> Prints the SDL error with specified message. </summary>
	void printSDLerror(std::string msg);

	/// <summary> Prints the SDL_IMG error with specified message. </summary>
	void printSDL_IMGerror(std::string msg);

	/// <summary> Prints the SDL_TTF error with specified message. </summary>
	void printSDL_TTFerror(std::string msg);
}