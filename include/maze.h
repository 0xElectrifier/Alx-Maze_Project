/** Header file containing prototypes of functions I wrote
 * and includes of external libraries used in this project
 */
#ifndef MAZE_H
#define MAZE_H


#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/* The Window the program will be rendering to */
extern SDL_Window *window;

/* The surface contained by the window */
extern SDL_Surface *screen_surface;

/* Map width */
extern int map_width;

/* Map height */
extern int map_height;

/* The Map of the Game */
#ifndef MAP_H
#define MAP_H

#define map_width 24
#define map_height 24

#endif

extern int world_map[map_width][map_height];

/* Prototype of init function */
bool init(void);

/* Renders the 2D map into a 3D map*/
int render_map(void);

#endif
