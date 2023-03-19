#ifndef MAZE_H
#define MAZE_H


/**
 * maze.h - Header file containing prototypes of functions I wrote
 * and includes of external libraries used in this project.
 */

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "raycast_struct.h"

/* The Window the program will be rendering to */
extern SDL_Window *window;

/* The surface contained by the window */
extern SDL_Surface *screen_surface;

/* SCREEN Width */
#define SCREEN_WIDTH 720

/* Screen Height */
#define SCREEN_HEIGHT 560

/* The Map of the Game */
#ifndef MAP_H
#define MAP_H

#define MAP_WIDTH 24
#define MAP_HEIGHT 24

#endif /* MAP_H */

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

/* Prototype of init function */
bool init(void);

/* Renders the 2D map into a 3D map*/
int render_map(void);

int game_loop(void);

int start_game_loop(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
		    RAY_DATA *r_data, TIMING_DATA *t_data);

int iterate_screen_width(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
			 RAY_DATA *r_data, TIMING_DATA *t_data);

int init_Ray_data(PLAYER_DATA *p_data, RAY_DATA *r_data, int x);

int init_PT_data(PLAYER_DATA *p_data, TIMING_DATA *t_data);

#endif /* MAZE_H */
