#include "maze.h"


/**
 * create_game_window - a singleton function that returns a
 *			static GAME_WINDOW object
 *
 * Return: pointer to a static GAME_WINDOW object, otherwise NULL on failure
 */
GAME_WINDOW *create_game_window(void)
{
	GAME_WINDOW *game_window = NULL;
	SDL_Window *window = NULL;
	SDL_Surface *screen_surface = NULL;
	SDL_Renderer *renderer = NULL;

	game_window = malloc(sizeof(GAME_WINDOW));
	if (game_window == NULL)
		return (NULL);

	/* Create Window */
	window = SDL_CreateWindow("Electrifier Maze", SDL_WINDOWPOS_UNDEFINED,
				  SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
				  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	/* On failure... */
	if (window == NULL)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return (NULL);
	}
	else
	{
		screen_surface = SDL_GetWindowSurface(window);
		if (screen_surface == NULL)
			return (NULL);
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer == NULL)
			return (NULL);
	}
	game_window->window = window;
	game_window->screen_surface = screen_surface;
	game_window->renderer = renderer;

	return (game_window);
}


/**
 * init - Initializes SDL
 *
 * Description: Calls the SDL initialization function,
 *		creates the game window and surface
 * Return: true (boolean) if the initialization was successful, otherwise false
 */

GAME_WINDOW *init(void)
{
	GAME_WINDOW *game_window = NULL;

	/* Initializing SDL */
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		/* On failure to initialize */
		printf("SDL could not initialize!\nSDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		game_window = create_game_window();
	}

	return (game_window);
}
