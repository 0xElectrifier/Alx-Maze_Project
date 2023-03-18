#include "maze.h"

/**
 * init - Initializes SDL
 *
 * Description: Calls the SDL initialization function,
 *		creates the game window and surface
 * Return: true (boolean) if the initialization was successful, otherwise false
 */

bool init(void)
{
	SDL_Window *window = NULL;
	SDL_Surface *screen_surface = NULL;
	SDL_Event e;
	(void) screen_surface;
	bool success = true;
	bool quit = false;

	/* Initializing SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		/* On failure to initialize */
		printf("SDL could not initialize!\nSDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		/* Create Window */
		window = SDL_CreateWindow("Electrifier Maze", SDL_WINDOWPOS_UNDEFINED,
					  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
					  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		/* On failure... */
		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			screen_surface = SDL_GetWindowSurface(window);

		}
	}

	return (success);
}
