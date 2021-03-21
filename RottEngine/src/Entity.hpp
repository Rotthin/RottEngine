#pragma once
#include <SDL.h>
#include "math/Vector2.hpp"

class Entity {
public:
	Entity(float x, float y, SDL_Texture* tex);
	
	/// <summary> Returns the position on the x axis. </summary>
	float getX();

	/// <summary> Returns the position on the y axis. </summary>
	float getY();

	/// <summary> Returns the width multiplied by scale. </summary>
	int getWidth();

	/// <summary> Returns the height multiplied by scale. </summary>
	int getHeight();

	/// <summary> Moves the entity by specified offset. </summary>
	void move(Vector2<float> offset);

	/// <summary> Renders the entity. </summary>
	virtual void render();

	/// <summary> Sets the position on the x axis to the specified value. </summary>
	void setX(float x);

	/// <summary> Sets the position on the y axis to the specified value. </summary>
	void setY(float y);

	/// <summary> Sets the sclae to the specified value. </summary>
	void setScale(const Vector2<float>& scale);

	/// <summary> Returns the entity's scale. </summary>
	Vector2<float> getScale();

	/// <summary> Returns the entity's position. </summary>
	Vector2<float> getPosition();

	/// <summary> Returns the entity's texture. </summary>
	SDL_Texture* getTexture();

	/// <summary> Returns the entity's source rect. </summary>
	SDL_Rect getRect();

protected:
	Vector2<float> m_scale;
	Vector2<float> m_position;
	SDL_Rect m_rect;
	SDL_Texture* mp_texture;
};

