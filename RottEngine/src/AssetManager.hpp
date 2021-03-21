#pragma once

#include <unordered_map>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_image.h>
#include <SDL.h>
#include <string>
#include "Logger.hpp"

class AssetManager {
public:
	/// <summary Adds texture with specified path to the map of textures. </summary>
	static void addTexture(SDL_Renderer* p_renderer, std::string path);

	/// <summary Returns texture from map with specified path. </summary>
	static SDL_Texture* getTexture(const char* path);

	/// <summary Adds font with specified path to the map of fonts. </summary>
	static void addFont(SDL_Renderer* p_renderer, std::string name, int fontSize);

	/// <summary Returns font from map with specified path. </summary>
	static TTF_Font* getFont(const char* path);

private:
	AssetManager();

	static std::unordered_map<std::string, SDL_Texture*> m_textures;
	static std::unordered_map<std::string, TTF_Font*> m_fonts;
};

