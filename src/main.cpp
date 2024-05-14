#include <iostream>
#include <SDL.h>

#include "Renderer.h"
#include "Grid.h"


int main(int argc, char* args[])
{
	//Start up SDL and create window
	Renderer renderer(800, 450);
	
	//create grid
	Grid grid(renderer.SCREEN_WIDTH, renderer.SCREEN_HEIGHT, std::complex<double>(-2, 1), 3);

	//map grid to fractal grid
	FractalGrid julia(85);
	julia.generate_fractal(grid.get());
	renderer.clear();
	renderer.render_fractal(julia);

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	//Free resources and close SDL
	renderer.close();

	return 0;
}