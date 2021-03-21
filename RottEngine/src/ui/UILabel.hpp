#pragma once

#include "UIEntity.hpp"
#include "../AssetManager.hpp"
#include "SDL/SDL_ttf.h"

#define LABEL_FLAGS_ALIGN_CENTER 1 << 0
#define LABEL_FLAGS_ALIGN_RIGHT  1 << 1
#define LABEL_FLAGS_QUALITY_BEST 1 << 2
#define LABEL_FLAGS_QUALITY_FAST  1 << 3

// TODO: Multiline support.
class UILabel : public UIEntity {
public:
	/// <summary> Some fonts looks actually better with fast quality flag. </summary>
	UILabel(SDL_Renderer* p_renderer, float x, float y, std::string text, std::string name, int flags=0, const SDL_Color& color = {255,255,255,255});

public:
	/// <summary> Sets the text and updates the texture. </summary>
	void setText(std::string text);

	/// <summary> Sets the color and updates the color. </summary>
	void setColor(const SDL_Color& color);

private:
	/// <summary> Creates text texture. </summary>
	void createTexture();

private:
	SDL_Surface* mp_surface;
	SDL_Renderer* mp_renderer;
	TTF_Font* mp_font;
	SDL_Color m_color;
	Vector2<float> m_targetPos;

	int m_flags;
	std::string m_text;
};

