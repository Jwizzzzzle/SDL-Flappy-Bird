#include "pipe.h"

#include "bird.h"

#include "../sdl/include/SDL.h"

#include <iostream>

void Pipe::start()
{
	scale = 1.5;
	x /= scale;
	y /= scale;
}

void Pipe::update()
{
	if (Collision())
		std::cout << "DEAD\n";

	x -= 1.0f;
	if (x <= -100 * scale)
	{
		x = 1280 / scale;
		y -= 10;
	}
}

void Pipe::setBird(Bird* bird)
{
	player = bird;
}

bool Pipe::Collision()
{
	SDL_Rect bird;
	bird.x = player->getX() * player->getScale();
	bird.y = player->getY() * player->getScale();
	bird.w = player->getSRC().w * player->getScale();
	bird.h = player->getSRC().h * player->getScale();

	SDL_Rect pipe;
	pipe.x = x * scale;
	pipe.y = y * scale;
	pipe.w = src.w * scale;
	pipe.h = src.h * scale;

	if (bird.x + bird.w >= pipe.x &&
		pipe.x + pipe.w >= bird.x &&
		bird.y + bird.h >= pipe.y &&
		pipe.y + pipe.h >= bird.y)
	{
		return true;
	}

	return false;
}