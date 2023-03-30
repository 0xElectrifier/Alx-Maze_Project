#include "maze.h"

/**
 * move_backwards - makes the player move backward
 * @rc_data: pointer to the RAYCAST_DATA struct
 *
 * Description: modifies the appropriate data to make the player move backward
 * Return: nothing
 */
void move_backwards(RAYCAST_DATA *rc_data)
{
	PLAYER_DATA *p_data = rc_data->player_data;
	TIMING_DATA *t_data = rc_data->timing_data;
	double dirX = p_data->dirX;
	double dirY = p_data->dirY;
	double posX = p_data->posX;
	double posY = p_data->posY;
	double moveSpeed = t_data->moveSpeed;
	int **world_map = rc_data->world_map;

	if (world_map[(int)(posX - dirX * moveSpeed)][(int)posY] == false)
		posX -= dirX * moveSpeed;

	if (world_map[(int)posX][(int)(posY - dirY * moveSpeed)] == false)
		posY -= dirY * moveSpeed;

	p_data->posX = posX;
	p_data->posY = posY;
}


/**
 * move_forward - makes the player move forward
 * @rc_data: pointer to the RAYCAST_DATA struct
 *
 * Description: modifies the appropriate data to make the player move backward
 * Return: nothing
 */
void move_forward(RAYCAST_DATA *rc_data)
{
	PLAYER_DATA *p_data = rc_data->player_data;
	TIMING_DATA *t_data = rc_data->timing_data;
	double dirX = p_data->dirX;
	double dirY = p_data->dirY;
	double posX = p_data->posX;
	double posY = p_data->posY;
	double moveSpeed = t_data->moveSpeed;
	int **world_map = rc_data->world_map;

	if (world_map[(int)(posX + dirX * moveSpeed)][(int)posY] == false)
		posX += dirX * moveSpeed;

	if (world_map[(int)posX][(int)(posY + dirY * moveSpeed)] == false)
		posY += dirY * moveSpeed;

	p_data->posX = posX;
	p_data->posY = posY;
}


/**
 * turn_right - makes the player move right
 * @rc_data: pointer to the RAYCAST_DATA struct
 *
 * Return: nothing
 */
void turn_right(RAYCAST_DATA *rc_data)
{
	PLAYER_DATA *p_data = rc_data->player_data;
	TIMING_DATA *t_data = rc_data->timing_data;
	double oldDirX, oldPlaneX;
	double dirX = p_data->dirX;
	double dirY = p_data->dirY;
	double planeX = p_data->planeX;
	double planeY = p_data->planeY;
	double rotSpeed = t_data->rotSpeed;

	oldDirX = dirX;
	dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed);
	dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
	oldPlaneX = planeX;
	planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
	planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);

	p_data->dirX = dirX;
	p_data->dirY = dirY;
	p_data->planeX = planeX;
	p_data->planeY = planeY;
}


/**
 * turn_left - makes the player move left
 * @rc_data: pointer to the RAYCAST_DATA struct
 *
 * Return: nothing
 */
void turn_left(RAYCAST_DATA *rc_data)
{
	PLAYER_DATA *p_data = rc_data->player_data;
	TIMING_DATA *t_data = rc_data->timing_data;
	double oldDirX, oldPlaneX;
	double dirX = p_data->dirX;
	double dirY = p_data->dirY;
	double planeX = p_data->planeX;
	double planeY = p_data->planeY;
	double rotSpeed = t_data->rotSpeed;

	oldDirX = dirX;
	dirX = dirX * cos(rotSpeed) - dirY * sin(rotSpeed);
	dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
	oldPlaneX = planeX;
	planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
	planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);

	p_data->dirX = dirX;
	p_data->dirY = dirY;
	p_data->planeX = planeX;
	p_data->planeY = planeY;
}
