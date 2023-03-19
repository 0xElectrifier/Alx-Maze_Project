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
	bool init_return;
	int g_loop_ret;
	(void) argc;
	(void) argv;

	init_return = init();
	if (init_return == false)
		return (-1);

	g_loop_ret = game_loop();
	if (g_loop_ret == -1)
		return (-1);

	return (0); /* Return on success */
}
