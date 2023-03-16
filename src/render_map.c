#include "maze.h"

/**
 * render_map - start formatting of map
 *
 *
 * Return: 
 */

int render_map(void)
{
	double posX = 22, posY = 12; /* x and y start position */
	double dirX = -1, dirY = 0; /* Initial direction vector */
	double planeX = 0, planeY = 0.66; /*The 2d raycaster version of camera plane*/
	double time = 0; /* Time of current frame */
	double oldTime = 0; /* Time of previous frame */

	double cameraX; /* x-coordinate in camera space */
	double rayDirX, rayDirY; /* The ray direction on the X and Y component */
	int x;
	SDL_Event e;
	bool quit;


	/* Game Loop start */
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			quit = true;

		for (x = 0; x < map_width; x++)
		{
			cameraX = ((2 * x) / double(w)) - 1;
			rayDirX = dirX + planeX * cameraX;
			rayDirY = dirY + planeY * cameraX;
		}

		if (quit == true)
			break;
	}

	return (0);
}
