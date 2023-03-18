#include "maze.h"

/**
 * init_PT_data - initializes and assigns values in the player_data
 *		  and TIMING_DATA struct
 * @p_data: pointer to a PLAYER_DATA struct
 * @t_data: pointer to a TIMING_DATA struct
 *
 * Return: 0 on success
 */
int init_PT_data(PLAYER_DATA *p_data, TIMING_DATA *t_data)
{
	/* Player structure data */
	(p_data)->posX = 22;
	(p_data)->posY = 12;
	(p_data)->dirX = -1;
	(p_data)->dirY = 0;
	(p_data)->planeX = 0;
	(p_data)->planeY = 0.66;

	/* Time structure data */
	(t_data)->time = 0;
	(t_data)->oldTime = 0;

	return (0);
}

/**
 * init_Ray_data - initializes and assigns values to player_data and ray_data
 * @p_data: PLAYER_DATA structure
 * @r_data: RAY_DATA structure
 * @x: current screen vertical component in iteration
 *
 * Return: 0 on success, otherwise 1
 */
int init_Ray_data(PLAYER_DATA *p_data, RAY_DATA *r_data, int x)
{
	/* Calculate ray position and direction */
	(r_data)->cameraX = ((2 * x) / (double)map_width) - 1;
	r_data->rayDirX = (p_data)->dirX + (p_data)->planeX * (r_data)->cameraX;
	r_data->rayDirY = (p_data)->dirY + (p_data)->planeY * (r_data)->cameraX;

	/* Which box of the map player is in */
	(r_data)->mapX = (int)(p_data)->posX;
	(r_data)->mapY = (int)(p_data)->posY;

	r_data->deltaDistX = r_data->rayDirX == 0 ? 1e30 : fabs(1 / r_data->rayDirX);
	r_data->deltaDistY = r_data->rayDirY == 0 ? 1e30 : fabs(1 / r_data->rayDirY);

	/* Calculate step and initial sideDist */
	if ((r_data)->rayDirX < 0)
	{
		(r_data)->stepX = -1;
		(r_data)->sideDistX = (p_data)->posX - (r_data)->mapX;
		(r_data)->sideDistX *= (r_data)->deltaDistX;
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
		(r_data)->sideDistY = ((p_data)->posY - (r_data)->mapY);
		(r_data)->sideDistY *= (r_data)->deltaDistY;
	}
	else
	{
		(r_data)->stepY = 1;
		(r_data)->sideDistY = ((r_data)->mapY + 1.0 - (p_data)->posY);
		(r_data)->sideDistY *= (r_data)->deltaDistY;
	}

	return (0);
}

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

	for (x = 0; x < map_width; x++)
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
			if (world_map[r_data->mapX][r_data->mapY] > 0)
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
	SDL_Event e;

	/* Stop loop when a defined user input is detected */
	while (SDL_PollEvent(&e) != 0)
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
 * load_map - creates the game map
 *
 * Description: loads the game map from a file and construct it into a pointer of arrays
 * Return: pointer to a 2D array of the game map on success, otherwise NULL
 */
int **load_map(void)
{
	char **map, code;
	int fd, code_int;

	map = malloc(sizeof(int *) * MAP_WIDTH);

	for (i = 0; i < MAP_WIDTH; i++)
	{
		map[i] = malloc(sizeof(int) * MAP_HEIGHT);
		if (map[i] == NULL)
			return (NULL);
	}

	fd = open("../maps/map.txt", O_RDONLY);
	if (fd < 0)
		retrun (NULL);
	for (i = 0; i < map_width; i++)
	{
		for (j = 0; j < map_height; j++)
		{
			code = fgetc(fd);
			if (code == '\n')
				continue;
			code_int = atoi(code);
			/* If atoi failed */
			if (code_int == 0 && code != '0')
				return (NULL);

			map[i][j] = code;
		}
	}
	close(fd);
	return (map);
}
/**
 * game_loop - handles game loop
 *
 * Return: 0 on success, otherwise 1
 */
int game_loop(void)
{
	RAYCAST_DATA *rc_data;

	/* Dynamically allocate memory to key structures [raycast_struct.h] */
	(rc_data) = malloc(sizeof(RAYCAST_DATA));
	if ((rc_data) == NULL)
		return (1);
	(rc_data)->player_data = malloc(sizeof(PLAYER_DATA));
	if ((rc_data)->player_data == NULL)
		return (1);
	(rc_data)->ray_data = malloc(sizeof(RAY_DATA));
	if ((rc_data)->ray_data == NULL)
		return (1);
	(rc_data)->timing_data = malloc(sizeof(TIMING_DATA));
	if ((rc_data)->timing_data == NULL)
		return (1);
	(rc_data)->world_map = load_map();

	/* Start game loop */
	start_game_loop(rc_data, (rc_data)->player_data,
			(rc_data)->ray_data, (rc_data)->timing_data);

	/* Free dynamically allocated memories */
	free(rc_data);
	free((rc_data)->player_data);
	free((rc_data)->ray_data);
	free((rc_data)->timing_data);

	return (0);
}
