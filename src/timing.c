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
	double maxFrameTime = 0.1;
	(void) maxFrameTime;

	t_data->oldTime = t_data->time;
	t_data->time = SDL_GetTicks();
	frameTime = (t_data->time - t_data->oldTime) / 1000.0;
	/**
	 * I noticed the frameTime increases on every iteration,
	 * which means the CPU kept slowing down.
	 *
	if (frameTime > maxFrameTime)
		frameTime = maxFrameTime;
	*
	printf("oldTime = %f\ntime = %f\n", t_data->oldTime, t_data->time);
	printf("frameTime = %f\n", frameTime);
	*/
	t_data->moveSpeed = frameTime * 5.0;
	t_data->rotSpeed = frameTime * 3.0;

	t_data->frameTime = frameTime;
}


/**
 * readKeysAndMove - reads the key pressed and changes the
 *		     player's view accordingly
 * @rc_data: pointer to the RAYCAST_DATA struct
 *
 * Return: nothing
 */
void readKeysAndMove(RAYCAST_DATA *rc_data)
{
	const Uint8 *keys;

	SDL_PumpEvents();
	keys = SDL_GetKeyboardState(NULL);

	/* Check key pressed and react accordingly */

	/* Move backwards if no wall is behind */
	if (keys[SDL_SCANCODE_DOWN] != 0 || keys[SDL_SCANCODE_S] != 0)
		move_backwards(rc_data);

	/* Move forward if no wall is behind */
	if (keys[SDL_SCANCODE_UP] != 0 || keys[SDL_SCANCODE_W] != 0)
		move_forward(rc_data);

	/* Rotate to the right */
	if (keys[SDL_SCANCODE_RIGHT] != 0 || keys[SDL_SCANCODE_D] != 0)
		turn_right(rc_data);

	/* Rotate to the left */
	if (keys[SDL_SCANCODE_LEFT] != 0 || keys[SDL_SCANCODE_A] != 0)
		turn_left(rc_data);
}
