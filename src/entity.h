#pragma once

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

class Entity
{
protected:
	SDL_Texture* texture;
	SDL_Rect src;
	float x, y;
	float scale = 1;
public:
	Entity(SDL_Texture* entityTexture, float xPos, float yPos, int textureWidth, int textureHeight);
	virtual void update();
	SDL_Texture* getTexture();
	SDL_Rect getSRC();
	float getX();
	float getY();
	float getScale();
};