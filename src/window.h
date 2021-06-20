#pragma once

#include "../sdl/include/SDL.h"
#include "../sdl/include/SDL_image.h"

class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool running = true;
public:
	Window(const char* title, int width, int height);
private:
	void loop();
	SDL_Texture* loadTexture(const char* filePath);
	void render(SDL_Texture* texture);
	void clear();
	void display();
	void cleanup();
};