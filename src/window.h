#pragma once

#include "entity.h"

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;
	bool isGameOver = false;
public:
	Window(const char* title, int width, int height);
private:
	void loop();
	SDL_Texture* loadTexture(const char* filePath);
	void render(Entity entity);
	void clear();
	void display();
	void cleanup();
};