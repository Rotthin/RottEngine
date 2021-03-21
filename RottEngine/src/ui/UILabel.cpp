#include "UILabel.hpp"

UILabel::UILabel(SDL_Renderer* rend, float x, float y, std::string txt, std::string name, int flags, const SDL_Color& col) :
UIEntity(0, 0, mp_texture),
mp_renderer(rend),
mp_font(AssetManager::getFont(name.c_str())),
m_color(col),
m_targetPos(x,y),
m_text(txt),
m_flags(flags) {
	createTexture();
}

void UILabel::createTexture() {
	// Destroy the previous texture, we dont need it anymore.
	SDL_DestroyTexture(mp_texture);

	// Create the new surface.
	if (m_flags & LABEL_FLAGS_QUALITY_FAST) {
		mp_surface = TTF_RenderText_Solid(mp_font, m_text.c_str(), m_color);
	} else {
		mp_surface = TTF_RenderText_Blended(mp_font, m_text.c_str(), m_color);
	}
	// Create the new texture.
	mp_texture = SDL_CreateTextureFromSurface(mp_renderer, mp_surface);
	
	// Free the just created surface. We dont need it anymore.
	SDL_FreeSurface(mp_surface);

	int w=0, h=0;

	// Align the text.
	TTF_SizeText(mp_font, m_text.c_str(), &w, &h);
	if (m_flags & LABEL_FLAGS_ALIGN_CENTER) { 
		m_position = {m_targetPos.x - ((float)(w*m_scale.x)/2), m_targetPos.y - ((float)(h*m_scale.y)/2)};
	} else if(m_flags & LABEL_FLAGS_ALIGN_RIGHT) { 
		m_position = {m_targetPos.x-(w*m_scale.x), m_targetPos.y-(h*m_scale.y)}; ;
	} else {
		m_position = m_targetPos;
	}

	// Set the width and height.
	SDL_QueryTexture(mp_texture, NULL, NULL, &w, &h);
	m_rect.w = w;
	m_rect.h = h;
}

void UILabel::setText(std::string text) {
	m_text = text;
	createTexture();
}

void UILabel::setColor(const SDL_Color& color) {
	m_color = color;
	createTexture();
}