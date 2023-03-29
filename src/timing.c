#include "maze.h"


/**
 * timing - handles the timing for the speed modifiers to determine the speed
 *	    of movement and rotation by the input keys
 * @t_data: pointer to a TIME_DATA structure
 *
 * Return: nothing
 */
void timing(TIMING_DATA *t_data)
{
	double frameTime;

	t_data->oldTime = t_data->time;
	t_data->time = SDL_GetTicks();
	frameTime = (t_data->time - t_data->oldTime) / 1000.0;

	t_data->moveSpeed = frameTime * 5.0;
	t_data->rotSpeed = frameTime * 3.0;

	t_data->frameTime = frameTime;
}


/**
 * readKeysAndMove - reads the key pressed and changes the player's view accordingly
 * @t_data: pointer to the TIMING_DATA struct
 *
 * Return: nothing
 */
void readKeysAndMove(RAYCAST_DATA *rc_data)
{
	Uint8 *keys;

	SDL_PumpEvents();
	keys = SDL_GetKeyState(NULL);

	/* Move backwards if no wall is behind */
	if (keys[SDLK_DOWN] != 0)
		move_backwards(rc_data);

	/* Move forward if no wall is behind */
	if (keys[SDLK_UP] != 0)
		move_forward(rc_data);

	/* Rotate to the right */
	if (keys[SDLK_RIGHT] != 0)
		turn_right(rc_data);

	/* Rotate to the left */
	if (keys[SDLK_LEFT] != 0)
		turn_left(rc_data);
}
