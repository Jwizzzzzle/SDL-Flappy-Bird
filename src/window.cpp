#include "window.h"

#include "entity.h"
#include "bird.h"
#include "pipe.h"

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
	SDL_Texture* birdTexture = loadTexture("rsrc/yellowbird-upflap.png");
	SDL_Texture* pipeTexture = loadTexture("rsrc/pipe-green.png");
	SDL_Texture* pipeTopTexture = loadTexture("rsrc/pipe-green-top.png");
	Bird bird(birdTexture, 640, 360, 34, 24);
	Pipe pipes[12];
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
			pipes[i] = Pipe(pipeTexture, i * 125, 460, 52, 320);
		else 
			pipes[i] = Pipe(pipeTopTexture, (i - 1) * 125, -280, 52, 320);
		pipes[i].start();
	}
	//Pipe pipe(pipeTexture, 640, 460, 52, 320);
	//Pipe pipeTop(pipeTopTexture, 640, -280, 52, 320);
	bird.start();

	//pipeTop.start();
	//pipe.start();

	SDL_Event event;

	while (running)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				running = false;
		}

		// Clear screen
		clear();
		// Update entities
		bird.update();
		//pipe.update();
		// Render entities
		render(bird);
		for (int i = 0; i < 12; i++)
		{
			pipes[i].update();
			render(pipes[i]);
		}
		//render(pipe);
		//render(pipeTop);
		// Display renderer to window
		display();
		// Wait
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

	src.x = entity.getSRC().x;
	src.y = entity.getSRC().y;
	src.w = entity.getSRC().w;
	src.h = entity.getSRC().h;

	screen.x = entity.getX() * entity.getScale();
	screen.y = entity.getY() * entity.getScale();
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