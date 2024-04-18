#include <iostream>


#include <SDL.h>
#include <SDL_image.h>

#include "Renderer.h";
#include "Grid.h";








// MAIN -------------------------------------- //

int main(int argc, char* args[])
{
	std::cout << "hello!" << std::endl;
	Renderer renderer(1080, 1080);
	//Start up SDL and create window
	
	Grid grid(renderer.SCREEN_WIDTH, renderer.SCREEN_HEIGHT);


	Fractal mandelbrot(50);
	mandelbrot.make_mandelbrot(grid.get());
	renderer.clear();
	//renderer.make_texture(mandelbrot);
	renderer.render_fractal(mandelbrot);
	std::cin.get();


	//Free resources and close SDL
	renderer.close();

	return 0;
}


// MAIN -------------------------------------- //



