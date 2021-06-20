#include "window.h"

#include "entity.h"

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

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

	loop();
	cleanup();
}

void Window::loop()
{
	SDL_Texture* texture = loadTexture("rsrc/yellowbird-upflap.png");
	Entity entity(texture, 0, 15, 34, 24);

	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
		}
		clear();
		render(entity);
		display();
		SDL_Delay(16);
	}
}

SDL_Texture* Window::loadTexture(const char* filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, filePath);
	if (texture == NULL)
		std::cout << "Failed to load texture! SDL_ERROR: " << SDL_GetError() << std::endl;

	return texture;
}

void Window::render(Entity entity)
{
	SDL_Rect src;
	SDL_Rect screen;

	src.x = 0;
	src.y = 0;
	src.w = entity.getSRC().w;
	src.h = entity.getSRC().h;

	screen.x = entity.getSRC().x * entity.getScale();
	screen.y = entity.getSRC().y * entity.getScale();
	screen.w = entity.getSRC().w * entity.getScale();
	screen.h = entity.getSRC().h * entity.getScale();

	SDL_RenderCopy(renderer, entity.getTexture(), &src, &screen);
}

void Window::clear()
{
	SDL_RenderClear(renderer);
}

void Window::display()
{
	SDL_RenderPresent(renderer);
}

void Window::cleanup()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}