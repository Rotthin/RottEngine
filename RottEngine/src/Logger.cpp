#include <iostream>
#include <SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "Logger.hpp"

void Logger::printSDLerror(std::string msg) {
	std::cerr << "SDL_ERROR: " << msg << ": " << SDL_GetError() << "\n";
}

void Logger::printSDL_IMGerror(std::string msg) {
	std::cerr<<"SDL_IMAGE_ERROR: "<< msg << ": " << IMG_GetError() << "\n";
}

void Logger::printSDL_TTFerror(std::string msg) {
	std::cerr<<"SDL_TTF_ERROR: "<<msg<<": "<<TTF_GetError()<<"\n";
}