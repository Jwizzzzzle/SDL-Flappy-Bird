#include "bird.h"

void Bird::start()
{
	scale = 1.5;
	x /= scale;
	y /= scale;
}

void Bird::update()
{
	y += delta;
	if (isSpace)
		delta = -2.0f;
	else 
		delta += 0.1f;

	angle = delta / 9 * 90.0f;
}