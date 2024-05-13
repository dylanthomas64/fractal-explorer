#include <iostream>


#include <SDL.h>

#include "Renderer.h";
#include "Grid.h";








// MAIN -------------------------------------- //

int main(int argc, char* args[])
{
	//std::cout << "hello!" << std::endl;
	Renderer renderer(500, 500);
	//Start up SDL and create window
	
	Grid grid(renderer.SCREEN_WIDTH, renderer.SCREEN_HEIGHT);


	Fractal julia(50);
	julia.make_mandelbrot(grid.get());
	renderer.clear();
	renderer.render_fractal(julia);

	//Hack to get window to stay up
	SDL_Event e; bool quit = false; while (quit == false) { while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; } }

	//Free resources and close SDL
	renderer.close();

	return 0;
}


// MAIN -------------------------------------- //



