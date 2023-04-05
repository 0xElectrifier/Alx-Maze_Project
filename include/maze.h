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

#define MAP_WIDTH 32
#define MAP_HEIGHT 32

#endif /* MAP_H */

extern int world_map[MAP_WIDTH][MAP_HEIGHT];

/* Prototype of init function */
GAME_WINDOW *init_sdl(void);

GAME_WINDOW *create_game_window(void);

RAYCAST_DATA *create_game_struct(GAME_WINDOW *game_window);

/* Renders the 2D map into a 3D map*/
int render_map(void);

int start_game_loop(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
		    RAY_DATA *r_data, TIMING_DATA *t_data);

int iterate_screen_width(RAYCAST_DATA *rc_data, PLAYER_DATA *p_data,
			 RAY_DATA *r_data, TIMING_DATA *t_data);

void perform_dda(int **world_map, RAY_DATA *r_data);

int **load_map(void);

int init_Ray_data(PLAYER_DATA *p_data, RAY_DATA *r_data, int x);

int init_PT_data(PLAYER_DATA *p_data, TIMING_DATA *t_data);

void free_rc_data(RAYCAST_DATA *rc_data);

SDL_Color *create_colors(void);

SDL_Color createColorSDL(Uint8 r, Uint8 g, Uint8 b, Uint8 a);

SDL_Color multiplyColorByScalar(SDL_Color color, double scalar);

SDL_Color divideColorByScalar(SDL_Color color, int scalar);

SDL_Color choose_wall_color(RAYCAST_DATA *rc_data, RAY_DATA *r_data);

void drawVerticalLine(GAME_WINDOW *game_window, int x, int startY, int endY, SDL_Color color);

bool drawVertLine(GAME_WINDOW *game_window, int x, int startY, int endY,
		  SDL_Color color);

void move_backwards(RAYCAST_DATA *rc_data);

void move_forward(RAYCAST_DATA *rc_data);

void turn_right(RAYCAST_DATA *rc_data);

void turn_left(RAYCAST_DATA *rc_data);

void readKeysAndMove(RAYCAST_DATA *rc_data);

void timing(TIMING_DATA *t_data);

#endif /* MAZE_H */
