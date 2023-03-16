/** Header file containing prototypes of functions I wrote
 * and includes of external libraries used in this project
 */
#ifndef MAZE_H
#define MAZE_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

/* The Window the program will be rendering to */
extern SDL_Window *window;

/* The surface contained by the window */
extern SDL_Surface *screen_surface;

/* Prototype of init function */
bool init(void);

#endif
