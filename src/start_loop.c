#include "maze.h"


/**
 * perform_dda - perform the DDA algorithm
 * @world_map: pointer to the game map
 * @r_data: pointer to the RAY_DATA struct
 *
 * Return: nothing
 */
void perform_dda(int **world_map, RAY_DATA *r_data)
{
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
}




/**
 * calc_line_height - Calculate the height of line to be drawn on screen
 * @r_data: pointer to the RAY_DATA struct
 *
 * Description: Calculate the height of line to be drawn on screen,
 *		along with the start and end position of the line
 * Return: nothing
 */
void calc_line_height(RAY_DATA *r_data)
{
	int lineHeight, drawStart, drawEnd;

	/* Calculate height of line to draw on screen */
	lineHeight = (int)(SCREEN_HEIGHT / (r_data)->perpWallDist);

	/* Calculate lowest and highest pixel to fill in current stripe */
	drawStart = -lineHeight / 2 + (SCREEN_HEIGHT / 2);
	if (drawStart < 0)
		drawStart = 0;

	drawEnd = lineHeight / 2 + SCREEN_HEIGHT /2;
	if (drawEnd >= SCREEN_HEIGHT)
		drawEnd = SCREEN_HEIGHT - 1;

	(r_data)->lineHeight = lineHeight;
	(r_data)->drawStart = drawStart;
	(r_data)->drawEnd = drawEnd;
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
	GAME_WINDOW *game_w;
	SDL_Color *colors, color, RGB_RED, RGB_BLUE, RGB_GREEN, RGB_WHITE, RGB_YELLOW;

	game_w = rc_data->game_w;
	colors = create_colors();

	for (x = 0; x < SCREEN_WIDTH; x++)
	{
		/* Assign values to the PLAYER_DATA and TIMING_DATA struct */
		init_PT_data(p_data, t_data);

		/* Calculate ray position and direction */
		init_Ray_data(p_data, r_data, x);

		/* Perform DDA */
		perform_dda((rc_data)->world_map, r_data);

		r_data->perpWallDist = (r_data->side == 0) ?
			(r_data->sideDistX - r_data->deltaDistX) :
			(r_data->sideDistY - r_data->deltaDistY);

		/* Calculate the height of line to be drawn on screen */
		calc_line_height(r_data);

		/* Choose Color */
		color = choose_wall_color(rc_data, r_data);

		SDL_SetRenderDrawColor(game_w->renderer, color.r, color.g, color.b, color.a);
		SDL_RenderDrawLine(game_w->renderer, x, r_data->drawEnd, x, r_data->drawStart);


		/*
		draw3DWall(game_w, x, SCREEN_HEIGHT, r_data->lineHeight,
			   r_data->drawStart, r_data->drawEnd, colors, r_data->cameraX, r_data->perpWallDist);


		* Draw the pixels of the stripe as a vertical line *
		drawVerticalLine(game_w, x, r_data->drawStart, r_data->drawEnd, color);*/

	}
	/* Present the renderer on the screen */
	SDL_RenderPresent(game_w->renderer);


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

	/* Start Game Loop, stop when a 'quit-event' is detected */
	while (quit == false)
	{
		/* Event Loop */
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				quit = true;
		}

		iterate_screen_width(rc_data, p_data, r_data, t_data);
	}

	return (0);
}



/**
 * game_loop - handles game loop
 *
 * Return: 0 on success, otherwise -1
 */
int game_loop(GAME_WINDOW *game_window)
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
		return (-1);
	(rc_data)->game_w = game_window;
	if ((rc_data)->game_w == NULL)
		return (-1);

	/* Start game loop */
	start_game_loop(rc_data, (rc_data)->player_data,
			(rc_data)->ray_data, (rc_data)->timing_data);

	free_rc_data(rc_data);

	return (0);
}
