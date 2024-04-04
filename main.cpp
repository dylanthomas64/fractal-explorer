#include <iostream>

int main() {
	std::cout << "hello!" << std::endl;
	return 0;
}


#include <SDL.h>
#include <SDL_image.h>

#include "Renderer.h";








// MAIN -------------------------------------- //

int main(int argc, char* args[])
{

	Renderer renderer;
	//Start up SDL and create window
	if (!renderer.init())
	{
		printf("Failed to initialize!\n");
	}

	//Free resources and close SDL
	renderer.close();

	return 0;
}


// MAIN -------------------------------------- //



