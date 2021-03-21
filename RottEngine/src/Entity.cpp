#include "Entity.hpp"
#include "EngineDefinitions.hpp"
#include "RenderWindow.hpp"

Entity::Entity(float x, float y, SDL_Texture* tex) : mp_texture(tex), m_position(x - HALF_UNIT_SIZE,y - HALF_UNIT_SIZE) {
	SDL_QueryTexture(tex, NULL, NULL, &m_rect.w, &m_rect.h);
	
	m_scale = {1.1};
}

void Entity::move(Vector2<float> offset) {
	m_position.x += offset.x;
	m_position.y += offset.y;
}

void Entity::render() {
	SDL_Rect dst;
	dst.x = getX();
	dst.y = getY();
	dst.w = getWidth();
	dst.h = getHeight();

	SDL_RenderCopy(RenderWindow::getRenderer(), mp_texture, &m_rect, &dst);
}

void Entity::setX(float x) {
	m_position.x = x;
}

void Entity::setY(float y) {
	m_position.y =y ;
}

void Entity::setScale(const Vector2<float>& scale) {
	m_scale = scale;
}

float Entity::getX()					{ return m_position.x; }

float Entity::getY()					{ return m_position.y; }

int Entity::getWidth()					{ return m_rect.w * m_scale.x; }

int Entity::getHeight()					{ return m_rect.h * m_scale.y; }

Vector2<float> Entity::getPosition()	{ return m_position; }

SDL_Rect Entity::getRect()				{ return m_rect; }

SDL_Texture* Entity::getTexture()		{ return mp_texture; }

Vector2<float> Entity::getScale()		{ return m_scale; }