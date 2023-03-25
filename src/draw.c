#include "maze.h"

/**
 * choose_wall_color - decides what color will be printed on a wall, depending on the position of the wall on the map
 * @rc_data: pointer to the RAYCAST_DATA object
 * @r_data: pointer to the RAY_DATA object
 *
 * Return: an SDL_Color object
 */
SDL_Color choose_wall_color(RAYCAST_DATA *rc_data, RAY_DATA *r_data)
{
	SDL_Color *colors, color;

	colors = create_colors();

	switch (rc_data->world_map[r_data->mapX][r_data->mapY])
	{
		case 1:
			color = colors[0];
			break;
		case 2:
			color = colors[1];
			break;
		case 3:
			color = colors[2];
			break;
		case 4:
			color = colors[3];
			break;
		default:
			color = colors[4];
			break;
	}

	/* Give x and y sides different brightness */
	if (r_data->side == 1)
		color = divideColorByScalar(color, 2);

	return (color);
}

/**
 * create_colors - creates an array of SDL_Color objects
 *
 * Return: pointer to an array of SDL_Color
 */
SDL_Color *create_colors(void)
{
	int color_count;
	SDL_Color RGB_RED, RGB_GREEN, RGB_BLUE, RGB_WHITE, RGB_YELLOW;
	SDL_Color *colors, temp;

	color_count = 5;
	colors = malloc(sizeof(SDL_Color) * color_count);
	if (colors == NULL)
		return (NULL);

	RGB_RED = createColorSDL(255, 0, 0, 255);
	RGB_GREEN = createColorSDL(0, 255, 0, 255);
	RGB_BLUE = createColorSDL(15, 82, 186, 255);
	RGB_WHITE = createColorSDL(255, 255, 255, 255);
	RGB_YELLOW = createColorSDL(255, 255, 0, 255);

	colors[0] = RGB_RED;
	colors[1] = RGB_GREEN;
	colors[2] = RGB_BLUE;
	colors[3] = RGB_WHITE;
	colors[4] = RGB_YELLOW;

	return (colors);
}


/**
 * createColorSDL - imitates the RBG color spectrum
 * @r: represents the RED component of the color (0-255)
 * @g: represents the GREEN component of the color (0-255)
 * @b: represents the BLUE component of the color (0-255)
 *
 * Description: constructs a ColorSDL color with the given
 *		red, green, blue and alpha values
 * Return: a ColorSDL object representing the specified color.
 */
SDL_Color createColorSDL(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	SDL_Color color = {r, g, b, a};
	return (color);
}

/**
 * multiplyColorByScalar: multiplies an SDL_Color object
 * @color: a SDL_Color object to be modified
 * @scalar: the value to multiply each color component by
 *
 * Return: nothing
 */
SDL_Color multiplyColorByScalar(SDL_Color color, double scalar)
{
	color.r = (Uint8)color.r * scalar;
	color.g = (Uint8)color.g * scalar;
	color.b = (Uint8)color.b * scalar;

	return (color);
}


/**
 * divideColorByScalar - divides a SDL_Color object
 * @color: a pointer to the SDL_Color object to be modified
 * @scalar: the value to divide each color component by
 *
 * Description: divides the red, green, and blue components of
 *		an SDL_Color object by a scalar value.
 * Return: nothing
 */
SDL_Color divideColorByScalar(SDL_Color color, int scalar)
{
	color.r = color.r / scalar;
	color.g = color.g / scalar;
	color.b = color.b / scalar;

	return (color);
}

/**
 * drawVerticalLine - modifies the pixels of the SDL_Surface pointed to by the 'surface' argument.
 * @game_window: pointer to a GAME_WINDOW object contain key
 *		game structures like the window, renderer and screen surface
 * @surface: a pointer to the SDL_Surface on which to draw the line
 * @x: the x-coordinate of the line
 * @startY: the y-coordinate of the start of the line
 * @endY: the y-coordinate of the end of the line
 * @color: the color of the line, represented as an SDL_Color struct
 *
 * Description: draws a vertical line of pixels in a given color
 *		from (x, yStart) to (x, yEnd) on an SDL_Surface.
 * Return: none
 */
void drawVerticalLine(GAME_WINDOW *game_window, int x, int startY,
		      int endY, SDL_Color color)
{
	int y;
	SDL_Renderer *renderer = game_window->renderer;

	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

	for (y = startY; y <= endY; y++)
	{
		SDL_RenderDrawPoint(renderer, x, y);
	}
}
