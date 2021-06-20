#include "entity.h"

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

Entity::Entity() { }

Entity::Entity(SDL_Texture* entityTexture, float xPos, float yPos, int textureWidth, int textureHeight)
:texture(entityTexture), x(xPos), y(yPos)
{
	src.x = 0;
	src.y = 0;
	src.w = textureWidth;
	src.h = textureHeight;
}

void Entity::start() { }

void Entity::update() { }

SDL_Texture* Entity::getTexture()
{
	return texture;
}

SDL_Rect Entity::getSRC()
{
	return src;
}

float Entity::getX()
{
	return x;
}

float Entity::getY()
{
	return y;
}

float Entity::getScale()
{
	return scale;
}

float Entity::getAngle()
{
	return angle;
}