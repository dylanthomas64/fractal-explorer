#include <iostream>
#include <SDL.h>

#include "Renderer.h"
#include "Grid.h"

enum class State {MENU, DISPLAY};


int main(int argc, char* args[])
{

	// init user input
	int option = 0;
	FractalType fractal_type = FractalType::none;

	// menu loop
	std::cout << "Welcome to fractal explorer!\n";
	
	SDL_Event e;

	//init loop flags
	bool quit = false;
	bool main_loop = true;



	while (!quit) {
		
		while (fractal_type == FractalType::none) {
			std::cout << "\n\nPlease choose a mode\n1 : mandelbrot\n2 : julia\n3 : mandelbrot + julia" << std::endl;
			std::cin >> option;
			if (std::cin.fail()) {
				// user didn't input a number
				std::cin.clear(); // reset failbit
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
			}
			switch (option) {
			case 1:
				fractal_type = FractalType::mandelbrot;
				std::cout << "MANDELBROT";
				break;
			case 2:
				fractal_type = FractalType::julia;
				std::cout << "JULIA";
				break;
			case 3:
				// just make a mandelbrot for now
				fractal_type = FractalType::mandelbrot;
				std::cout << "MANDELBROT + JULIA";
				break;
			default:
				std::cout << "please choose a valid option...\n";
				break;
			}
		}

		//return 0;

		//Start up SDL and create window
		Renderer renderer(800, 450);

		//create grid
		Grid grid(renderer.SCREEN_WIDTH, renderer.SCREEN_HEIGHT, std::complex<double>(-2, 1), 3);

		//map grid to fractal grid
		FractalGrid fractal(85, fractal_type);
		fractal.generate_fractal(grid.get());
		renderer.clear();
		renderer.render_fractal(fractal);





		
		while (main_loop)
		{
			while (SDL_PollEvent(&e))
			{
				if (e.type == SDL_QUIT)
				{
					quit = true;
				}
				if (e.type == SDL_KEYDOWN) {
					switch (e.key.keysym.sym)
					{
						case SDLK_q:
							fractal_type = FractalType::none;
							main_loop = false;

					}
				}
			}
		}
		
		// reset main_loop
		main_loop = true;

	}
	//Free resources and close SDL
	


	return 0;
}

