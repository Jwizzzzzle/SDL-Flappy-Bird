#pragma once

#include "../sdl/include/SDL.h"

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
public:
	Window(const char* title, int width, int height);
	void cleanup();
};