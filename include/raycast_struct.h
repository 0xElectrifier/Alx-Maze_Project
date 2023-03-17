#ifndef RC_DATA
#define RC_DATA


/**
 * PLAYER_DATA - struct for position/direction data
 * @posX: x start position
 * @posY: y start position
 * @dirX: x initial direction vector
 * @dirY: y initial direction vector
 * @planeX: the 2D raycaster version of camera plane on X axis
 * @planeY: the 2D raycaster version of camera plane on Y axis
 *
 * Description: Contains the position and direction data for raycasting
 */
typedef struct
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
} PLAYER_DATA;


/**
 * RAY_DATA - Single ray data
 *
 * @rayDirX: the ray direction on the X component
 * @rayDirY: the ray direction on the Y component
 * @mapX: 
 * @mapY:
 * @sideDistX: length of ray from current position to next x-side
 * @sideDistY: length of ray from current position to next y-side
 * @deltaDistX: length of ray from one x-side to next x-side
 * @deltaDistY: length of ray from one y-side to next y-side
 * @perpWallDist:
 * @stepX: What direction to step in x-direction (either +1 or -1) 
 * @stepY: What direction to step in y-direction (either +1 or -1)
 * @hit: tracks if a wall was hit
 * @side: tracks if a NS or a EW wall hit
 *
 * Description: Struct that contains the raycasting data for a single ray.
 */
typedef struct
{
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
} RAY_DATA


/**
 * TIMING_DATA - timing data.
 *
 * @time: time of current frame
 * @oldTime: time of previous frame
 * @cameraX: x-coordinate in camera space
 *
 * Description: struct that contains timing data for raycasting.
 */
typedef struct
{
	double time;
	double oldTime;
	double cameraX;
} TIMING_DATA;


/**
 * RAYCAST_DATA - contains all the data required for raycasting
 *
 * @e: tracks events that has occurred in the system, usually user input
 * @player_data: data type 'PLAYER_DATA'
 * @ray_data: data type 'RAY_DATA'
 * @timing_data: data type 'TIMING_DATA'
 *
 * Description: A combination of the 3 key data structs which were broken down
 *		to simpler bits to be used by the Raycasting Algorithm (DDA).
 */
typedef struct
{
	SDL_Event e;
	PLAYER_DATA player_data;
	RAY_DATA ray_data;
	TIMING_DATA timing_data;
} RAYCAST_DATA;


#endif /* RC_DATA */
