#include "window.h"

#include <iostream>

Window::Window(const char* title, int width, int height)
:window(NULL), renderer(NULL)
{
	// Create window and error check
	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
	if (window == NULL)
		std::cout << "Eroor creating window. SDL_ERROR: " << SDL_GetError() << std::endl;

	// Create renderer and error check
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
		std::cout << "Error creating renderer. SDL_ERROR: " << SDL_GetError() << std::endl;

	SDL_Delay(3000);

	cleanup();
}

void Window::cleanup()
{
	SDL_DestroyWindow(window);
}