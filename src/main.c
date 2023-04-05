#include "maze.h"

/**
 * main - main function to the Maze game
 * @argc: the number of arguments passed on terminal
 * @argv: pointer to an array of pointers/strings passed on terminal
 *
 * Description: A 3D Maze game built with Raycasting
 * Return: 0 if successful otherwise -1
 */

int main(int argc, char **argv)
{
	GAME_WINDOW *game_window;
	RAYCAST_DATA *rc_data;
	(void) argc;
	(void) argv;

	/* Initializes SDL as well as create the game window and renderer */
	game_window = init_sdl();
	if (game_window == false)
		return (-1);

	/**
	 * Declare variable 'rc_data' and dynamically allocate memory to it
	 * and its embedded fields.
	 * rc_data is a RAYCAST_DATA struct that contains most data
	 * such as player data, ray data and so on.
	 */
	rc_data = create_game_struct(game_window);
	if (rc_data == NULL)
	{
		printf("Couldn't create game struct\n");
		return (-1);
	}


	/* Start game loop */
	start_game_loop(rc_data, (rc_data)->player_data,
			(rc_data)->ray_data, (rc_data)->timing_data);

	/* Free all dynamically allocated memory */
	free_rc_data(rc_data);

	return (0); /* Return on success */
}
