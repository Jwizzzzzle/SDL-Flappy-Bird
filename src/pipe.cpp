#include "pipe.h"

void Pipe::start()
{
	scale = 1.5;
	x /= scale;
	y /= scale;
}

void Pipe::update()
{
	x -= 1.0f;
	if (x <= -100 * scale)
		x = 1280 / scale;
}