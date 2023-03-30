#include "maze.h"


/**
 * free_rc_data - frees the RAYCAST_DATA struct and every field in the struct
 * @rc_data: pointer to the RAYCAST_DATA struct to free
 *
 * Return: nothing
 */
void free_rc_data(RAYCAST_DATA *rc_data)
{
	int i;
	GAME_WINDOW *game_w = rc_data->game_w;

	/* Free SDL_Surface *
	SDL_FreeSurface(game_w->screen_surface);
	*/
	/* Free SDL_Renderer */
	SDL_DestroyRenderer(game_w->renderer);
	/* Free SDL_Window */
	SDL_DestroyWindow((game_w)->window);

	/* Free GAME_WINDOW */
	free(game_w);

	/* Free PLAYER_DATA */
	free((rc_data)->player_data);

	/* Free RAY_DATA */
	free((rc_data)->ray_data);

	/* Free TIMING_DATA */
	free((rc_data)->timing_data);

	/* Free world_map field in rc_data */
	for (i = 0; i < MAP_HEIGHT; i++)
	{
		free((rc_data)->world_map[i]);
	}
	free((rc_data)->world_map);

	/* Free RAYCAST_DATA */
	free(rc_data);
}
