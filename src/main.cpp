#define SDL_MAIN_HANDLED

#include "window.h"

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

#include <iostream>

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO) > 0)
		std::cout << "SDL_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
	if (!IMG_Init(IMG_INIT_PNG))
		std::cout << "IMG_Init has failed! SDL_ERROR: " << SDL_GetError() << std::endl;
	
	Window window("Flappy Bird", 1280, 720);
	return 0;
}