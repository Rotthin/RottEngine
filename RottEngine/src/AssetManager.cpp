#include "AssetManager.hpp"

std::unordered_map<std::string, SDL_Texture*> AssetManager::m_textures;
std::unordered_map<std::string, TTF_Font*> AssetManager::m_fonts;

void AssetManager::addTexture(SDL_Renderer* p_renderer, std::string name) {
	SDL_Texture* texture = IMG_LoadTexture(p_renderer, ("res/gfx/" + name + ".png").c_str());

	if (!texture) {
		Logger::printSDL_IMGerror("Couldn't load texture ("+std::string(name)+")");
		return;
	}

	m_textures.emplace(name, texture);
}

SDL_Texture* AssetManager::getTexture(const char* path) {
	return m_textures[path];
}

void AssetManager::addFont(SDL_Renderer* p_renderer, std::string name, int fontSize) {
	m_fonts.emplace(name, TTF_OpenFont(("res/fonts/" + name + ".ttf").c_str(), fontSize));
}

TTF_Font* AssetManager::getFont(const char* path) {
	return m_fonts[path];
}