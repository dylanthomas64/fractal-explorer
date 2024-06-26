#pragma once
#include <SDL.h>
#include "Fractal.h"


class Renderer {
public:
	

	Renderer(int w, int h);
	~Renderer();
	//methods

	//Starts up SDL and creates window
	bool init();

	//render texture to screen
	bool render_texture();

	bool render_fractal(FractalGrid fractal);

	bool clear();
	bool make_texture(FractalGrid);

	//Frees media and shuts down SDL
	void close();

	//Screen dimension constants
	int SCREEN_WIDTH;
	int SCREEN_HEIGHT;

	//The window we'll be rendering to
	SDL_Window* window = NULL;

	//The window renderer
	SDL_Renderer* renderer = NULL;

	// texture to be rendered
	SDL_Texture* texture = NULL;

};
