#include "background.h"

void BG::start()
{
	scale = 1.5;
	x /= scale;
	y /= scale;
}

void BG::update()
{
	x -= 1.0f;
	if (x <= -425 * scale)
		x = 1280 / scale;
}