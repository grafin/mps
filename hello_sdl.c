/*This source code copyrighted by Lazy Foo' Productions (2004-2022)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#include <SDL2/SDL.h>
#include <stdio.h>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	int rc = 0;

	//The window we'll be rendering to
	SDL_Window *window = NULL; /* NULL == 0 */

	//The surface contained by the window
	SDL_Surface *screenSurface = NULL;

	//Initialize SDL
	if((rc = SDL_Init(SDL_INIT_VIDEO)) != 0) {
		printf("SDL could not initialize! SDL_Error: %s\n",
			SDL_GetError());
		goto quit;
	}

	//Create window
	window = SDL_CreateWindow(
		"Hello SDL!",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN
	);

	if(window == NULL) {
		printf("Window could not be created! SDL_Error: %s\n",
			SDL_GetError());
		rc = -1;
		goto sdl_quit;
	}

	//Get window surface
	screenSurface = SDL_GetWindowSurface(window);

	//Fill the surface white
	SDL_FillRect(screenSurface, NULL,
		SDL_MapRGB(screenSurface->format, 0xFF, 0x00, 0x00));

	//Update the surface
	SDL_UpdateWindowSurface(window);

	//Wait two seconds
	SDL_Delay(2000);

	//Destroy window
	SDL_DestroyWindow(window);

//Quit SDL subsystems
sdl_quit:
	SDL_Quit();
quit:
	return rc;
}
