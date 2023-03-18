#include "maze.h"


/**
 * ray_player_data - initializes and assigns values to player_data and ray_data
 * @p_data: PLAYER_DATA structure
 * @r_data: RAY_DATA structure
 *
 * Return: 0 on success, otherwise 1
 */
int ray_player_data(PLAYER_DATA *p_data, RAY_DATA *r_data)
{
	/* Calculate ray position and direction */
	(r_data)->cameraX = ((2 * x) / double(map_width)) - 1;
	(r_data)->rayDirX = (p_data)->dirX + (p_data)->planeX * (r_data)->cameraX;
	(r_data)->rayDirY = (p_data)->dirY + (p_data)->planeY * (r_data)->cameraX;

	/* Which box of the map player is in */
	(r_data)->mapX = (p_data)->((int)posX);
	(r_data)->mapY = (p_data)->((int)posY);

	(r_data)->deltaDistX = (r_data)->rayDirX == 0 ? 1e30 : fabs(1 / r_data->rayDirX);
	(r_data)->deltaDistY = (r_data)->rayDirY == 0 ? 1e30 : fabs(1 / r_data->rayDirY);

	/* Calculate step and initial sideDist */

	if ((r_data)->rayDirX < 0)
	{
		(r_data)->stepX = -1;
		(r_data)->sideDistX = ((p_data)->posX - (r_data)->mapX) * (r_data)->deltaDistX;
	}
	else
	{
		(r_data)->stepX = 1;
		(r_data)->sideDistX = (r_data)->mapX + 1.0 - (p_data)->posX;
		(r_data)->sideDistX *= (r_data)->deltaDistX;
	}
	if ((r_data)->rayDirY < 0)
	{
		(r_data)->stepY = -1;
		(r_data)->sideDistY = ((p_data)->posY - (r_data)->mapY) * (r_data)->deltaDistY;
	}
	else
	{
		(r_data)->stepY = 1;
		(r_data)->sideDistY = ((r_data)->mapY + 1.0 - (p_data)->posY) * (r_data)->deltaDistY;
	}

	return (0);
}

/**
 * iterate_screen_width - iterates through the vertical components of the screen
 * @rc_data: RAYCAST_DATA struct
 * @p_data: PLAYER_DATA struct
 * @r_data: RAY_DATA struct
 * @t_data: TIMING_DATA struct
 *
 * Return: 0 on successful iteration, otherwise 1
 */
int iterate_screen_width(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
			 RAY_DATA *r_data, TIMING_DATA *t_data)
{
	int x;

	for (x = 0; x < map_width; x++)
	{
		/* Calculate ray position and direction */
		ray_player_data(p_data, r_data);

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
			if (world_map[mapX][mapY] > 0)
				hit = 1;
		}

		perpWallDist = (r_data->side == 0) ? (r_data->sideDistX - r_data->deltaDistX) : (r_data->sideDistY - r_data->deltaDistY);
	}
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
 * Return: 
 */

/**
 * double posX = 22, posY = 12;
 * double dirX = -1, dirY = 0;
 * double planeX = 0, planeY = 0.66;
 * double time = 0, oldTime = 0;
 */

int start_game_loop(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
		    RAY_DATA *r_data, TIMING_DATA *t_data)
{
	bool quit = false;

	/* Stop loop when a defined user input is detected */
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			quit = true;

		iterate_screen_width(rc_data, p_data, r_data, t_data);

		if (quit == true)
			break;
	}

	return (0);
}

/**
 * game_loop - handles game loop
 *
 * Return:
 */
int game_loop(void)
{
	RAYCAST_DATA *rc_data;

	rc_data = malloc(sizeof(RAYCAST_DATA));
	if (rc_data == NULL)
		return (1);
	rc_data->player_data = malloc(sizeof(PLAYER_DATA));
	if (rc_data->player_data == NULL)
		return (1);
	rc_data->ray_data = malloc(sizeof(RAY_DATA));
	if (rc_data->ray_data == NULL)
		return (1);
	rc_data->timing_data = malloc(sizeof(TIMING_DATA));
	if (rc_data->timing_data == NULL)
		return (1);

	start_game_loop(rc_data, rc_data->player_data,
			rc_data->ray_data, rc_data->timing_data);

	return (0);
}
