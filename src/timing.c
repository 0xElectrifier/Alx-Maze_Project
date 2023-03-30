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
 * readKeysAndMove - reads the key pressed and changes the player's view accordingly
 * @t_data: pointer to the TIMING_DATA struct
 * @event: SDL_Event structure containing current event to be logged
 *
 * Return: nothing
 */
void readKeysAndMove(RAYCAST_DATA *rc_data, SDL_Event event)
{
	/*
	SDL_PumpEvents();
	keys = SDL_GetKeyState(NULL);
	*/

	/* Check key pressed and react accordingly */
	switch (event.key.keysym.sym)
	{
		case SDLK_DOWN:
			move_backwards(rc_data);
		case SDLK_UP:
			move_forward(rc_data);
		case SDLK_RIGHT:
			turn_right(rc_data);
		case SDLK_LEFT:
			turn_left(rc_data);
		default:
			;
	}
}
