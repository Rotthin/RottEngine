#pragma once
#include "../Entity.hpp"

class UIEntity : public Entity {
public:
	UIEntity(float x, float y, SDL_Texture* p_tex);
};

