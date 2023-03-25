#include "maze.h"

/**
 * draw3DWall - modifies the pixels on the screen within the bounds of the wall
 * @renderer: a pointer to the SDL_Renderer object used to draw on the screen
 * @x: the x-coordinate of the vertical slice on the screen
 * @screenHeight: the height of the screen, in pixels
 * @wallHeight: the height of the wall, in pixels
 * @startY: the starting y-coordinate of the wall slice
 * @endY: the ending y-coordinate of the wall slice
 * @color: a pointer to an SDL_Color object representing the color of the wall
 * @textureX: the x-coordinate of the texture to sample from, in the range [0, texture width)
 * @perpWallDist: the perpendicular distance from  the player to the wall slice
 *
 * Description: draws a 3D wall on the screen using the given parameters
 * Return: none
 */
void draw3DWall(GAME_WINDOW *game_w, int x, int screenHeight,
		int wallHeight, int startY, int endY, SDL_Color *colors,
		int textureX, double perpWallDist)
{
	int texelHeight, y;
	double texelStep, texelPos;
	SDL_Color color;

	texelHeight = wallHeight / (endY - startY + 1);
	texelStep = 1.0 / (double)texelHeight;
	texelPos = ((double)startY - (double)screenHeight / 2.0 + (double)wallHeight / 2.0) * texelStep;

	for (y = startY; y <= endY; y++)
	{
		int texelIndex = (int)texelPos;
		texelPos += texelStep;
		color = colors[texelIndex];
		color = multiplyColorByScalar(color, (1.0 / perpWallDist));
		drawVerticalLine(game_w, x, y, y + texelHeight - 1, color);
	}
}
