#include "maze.h"


/**
 * iterate_screen_width - iterates through the vertical components
 *			  of the screen
 * @rc_data: RAYCAST_DATA struct
 * @p_data: pointer to a PLAYER_DATA struct
 * @r_data: pointer to a RAY_DATA struct
 * @t_data: pointer to a TIMING_DATA struct
 *
 * Return: 0 on successful iteration, otherwise 1
 */
int iterate_screen_width(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
			 RAY_DATA *r_data, TIMING_DATA *t_data)
{
	int x;

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		/* Assign values to the PLAYER_DATA and TIMING_DATA struct */
		init_PT_data(p_data, t_data);

		/* Calculate ray position and direction */
		init_Ray_data(p_data, r_data, x);

		/* Perform DDA */
		(r_data)->hit = 0;
		while ((r_data)->hit == 0)
		{
			/* Jump to next map square, either in x-direction, or in y-direction */
			if ((r_data)->sideDistX < (r_data)->sideDistY)
			{
				(r_data)->sideDistX += (r_data)->deltaDistX;
				(r_data)->mapX += (r_data)->stepX;
				(r_data)->side = 0;
			}
			else
			{
				r_data->sideDistY += r_data->deltaDistY;
				r_data->mapY += r_data->stepY;
				r_data->side = 1;
			}
			/* Check if ray has hit a wall */
			if (rc_data->world_map[r_data->mapX][r_data->mapY] > 0)
				r_data->hit = 1;
		}

		r_data->perpWallDist = (r_data->side == 0) ?
			(r_data->sideDistX - r_data->deltaDistX) :
			(r_data->sideDistY - r_data->deltaDistY);
	}

	return (0);
}


/**
 * start_game_loop - handles game loop
 * @rc_data: RAYCAST_DATA struct
 * @p_data: PLAYER_DATA struct
 * @r_data: RAY_DATA struct
 * @t_data: TIMING_DATA struct
 *
 * Description: this function begins the game loop, iterating through
 *		the vertical axis of the screen so images can be rendered.
 * Return: 0 on success
 */

int start_game_loop(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
		    RAY_DATA *r_data, TIMING_DATA *t_data)
{
	bool quit = false;
	int i = 0;
	SDL_Event e;

	/* Start Game Loop, stop when a 'quit-event' is detected */
	while (quit == false)
	{
		/* Event Loop */
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}
		i++;

		iterate_screen_width(rc_data, p_data, r_data, t_data);
	}

	return (0);
}



/**
 * game_loop - handles game loop
 *
 * Return: 0 on success, otherwise -1
 */
int game_loop(void)
{
	RAYCAST_DATA *rc_data;

	/* Dynamically allocate memory to key structures [raycast_struct.h] */
	(rc_data) = malloc(sizeof(RAYCAST_DATA));
	if ((rc_data) == NULL)
		return (-1);
	(rc_data)->player_data = malloc(sizeof(PLAYER_DATA));
	if ((rc_data)->player_data == NULL)
		return (-1);
	(rc_data)->ray_data = malloc(sizeof(RAY_DATA));
	if ((rc_data)->ray_data == NULL)
		return (-1);
	(rc_data)->timing_data = malloc(sizeof(TIMING_DATA));
	if ((rc_data)->timing_data == NULL)
		return (-1);
	(rc_data)->world_map = load_map();
	if ((rc_data)->world_map == NULL)
	{
		printf("Could not create map\n");
		return (-1);
	}

	/* Start game loop */
	start_game_loop(rc_data, (rc_data)->player_data,
			(rc_data)->ray_data, (rc_data)->timing_data);

	free_rc_data(rc_data);

	return (0);
}
