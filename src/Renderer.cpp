#include "Renderer.h"
#include<iostream>



Renderer::Renderer(int w, int h) : SCREEN_WIDTH(w), SCREEN_HEIGHT(h) {
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
}

Renderer::~Renderer() {
	close();
}

bool Renderer::init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		window = SDL_CreateWindow("Fractal Explorer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
			if (renderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				texture = SDL_CreateTexture(this->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, SCREEN_WIDTH, SCREEN_HEIGHT);

				if (renderer == NULL)
				{
					printf("Texture could not be created! SDL Error: %s\n", SDL_GetError());
					success = false;
				}
				//Initialize renderer color
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool Renderer::clear() {
	if (this->renderer == nullptr) {
		std::cout << "renderer is a nullptr yo!";
		return false;
	}

	SDL_SetRenderDrawColor(this->renderer, 0xAA, 0xFF, 0xAA, 0xFF);
	SDL_RenderClear(this->renderer);
	//SDL_RenderPresent(this->renderer);
	return true;
}

bool Renderer::render_texture() {
	if (texture == nullptr) {
		std::cout << "texture doesn't exist";
	}
	SDL_SetRenderDrawColor(renderer, 0x00, 0xFF, 0x11, 0xFF);
	SDL_RenderClear(renderer);
	//SDL_RenderCopy(renderer, texture, nullptr, nullptr);
	SDL_RenderPresent(renderer);
	return true;
}

bool Renderer::render_fractal (Fractal fractal) {
	// clear existing texture
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);


	//std::cout << "rendering grid";

	//double weight = 0xFF / fractal
	
	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			//std::cout << iterations_grid.at(y).at(x) << "\t";
			if (fractal.iterations_grid.at(y).at(x) == 0) {
				SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderDrawPoint(renderer, x, y);
			}
			else {
				int weight = 0xFF / fractal.max_iterations;
				SDL_SetRenderDrawColor(renderer, 0x00, 0x00, weight*fractal.iterations_grid.at(y).at(x), 0xFF);
				SDL_RenderDrawPoint(renderer, x, y);
				
			}
			

		}
	}
	SDL_RenderPresent(renderer);
	return true;
}

bool Renderer::make_texture(Fractal fractal) {
	// clear existing texture
	SDL_SetRenderTarget(renderer, texture);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(renderer);



	for (int y = 0; y < SCREEN_HEIGHT; y++) {
		for (int x = 0; x < SCREEN_WIDTH; x++) {
			double weight = fractal.iterations_grid.at(y).at(x) / fractal.max_iterations;
			SDL_SetRenderDrawColor(renderer, 0xFF * weight, 0x12, 0x22, 0xFF);
			SDL_RenderDrawPoint(renderer, x, y);
			
		}
	}
	//reset render target to renderer
	SDL_SetRenderTarget(renderer, nullptr);
	return true;
}


void Renderer::close()
{
	//Free loaded images
	//image_class.free();

	//Destroy window	
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = nullptr;
	renderer = nullptr;
	texture = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}