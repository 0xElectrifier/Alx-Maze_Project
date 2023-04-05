/**
 * drawVertLine - modifies the pixels of the SDL_Surface pointed to
 *		  by the 'surface' argument.
 * @x: the x-coordinate of the line
 * @startY: the y-coordinate of the start of the line
 * @endY: the y-coordinate of the end of the line
 * @color: the color of the line, represented as an SDL_Color struct
 * @game_window: pointer to a GAME_WINDOW object contain key
 *		 game structures like the window, renderer and screen surface
 * Return: true on success, otherwise false
 */
bool drawVertLine(GAME_WINDOW *game_window, int x, int startY, int endY,
		  SDL_Color color)
{
	int y, temp;
	SDL_Surface *surface = NULL;
	SDL_Renderer *renderer = NULL;

	surface = game_window->screen_surface;
	renderer = game_window->renderer;
	/* Swap startY and endY if endY is less than startY */
	if (endY < startY)
	{
		temp = startY;
		startY = endY;
		endY = temp;
	}

	/* Check if any point of the line is off-screen */
	if (endY < 0 || startY >= surface->h || x < 0 || x >= surface->w)
	{
		return (false);
	}
	SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, SDL_ALPHA_OPAQUE);

	/* Draw current vertical line at 'x' from startY to endY */
	for (y = startY; y <= endY; y++)
	{
		SDL_RenderDrawPoint(renderer, x, y);
	}	return (true);

	return (true);
}
