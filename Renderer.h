#pragma once


#include <SDL.h>
#include <SDL_image.h>

class Renderer {
public:
	//Screen dimension constants
	int SCREEN_WIDTH = 560;
	int SCREEN_HEIGHT = 560;

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;

	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	//methods

	//Starts up SDL and creates window
	bool init();

	//render to screen
	bool render();

	//Loads media
	bool loadMedia();

	//Frees media and shuts down SDL
	void close();

};
