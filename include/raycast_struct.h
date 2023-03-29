#ifndef RC_DATA
#define RC_DATA


/**
 * struct PLAYER_DATA - struct for position/direction data
 * @posX: x start position
 * @posY: y start position
 * @dirX: x initial direction vector
 * @dirY: y initial direction vector
 * @planeX: the 2D raycaster version of camera plane on X axis
 * @planeY: the 2D raycaster version of camera plane on Y axis
 *
 * Description: Contains the position and direction data for raycasting
 */
typedef struct PLAYER_DATA
{
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
} PLAYER_DATA;


/**
 * struct RAY_DATA - Single ray data
 *
 * @rayDirX: the ray direction on the X component
 * @rayDirY: the ray direction on the Y component
 * @deltaDistX: length of ray from one x-side to next x-side
 * @deltaDistY: length of ray from one y-side to next y-side
 * @sideDistX: length of ray from current position to next x-side
 * @sideDistY: length of ray from current position to next y-side
 * @perpWallDist: the perpendicular distance between the player's position
 *		  and the wall that is hit by the ray.
 * @cameraX: the x-coordinate on the camera plane that the current
 *	     x-coordinate of the screen represents.
 * @mapX: the x-coordinate of the current square of the map the ray is in
 * @mapY: the y-coordinate of the current square of the map the ray is in
 * @stepX: What direction to step in x-direction (either +1 or -1)
 * @stepY: What direction to step in y-direction (either +1 or -1)
 * @hit: tracks if a wall was hit
 * @side: tracks if a NS or a EW wall hit
 *
 * Description: Struct that contains the raycasting data for a single ray.
 */
typedef struct RAY_DATA
{
	double rayDirX;
	double rayDirY;
	double deltaDistX;
	double deltaDistY;
	double sideDistX;
	double sideDistY;
	double perpWallDist;
	double cameraX;
	int mapX;
	int mapY;
	int stepX;
	int stepY;
	int hit;
	int side;
	int lineHeight;
	int drawStart;
	int drawEnd;
} RAY_DATA;


/**
 * struct TIMING_DATA - timing data.
 *
 * @time: time of current frame
 * @oldTime: time of previous frame
 * @frameTime: time a current frame has taken, in seconds
 * @moveSpeed: movement speed with value in squares/second
 * @rotSpeed: rotation speed with value in squares/second
 *
 * Description: struct that contains timing data for raycasting.
 */
typedef struct TIMING_DATA
{
	double time;
	double oldTime;
	double frameTime;
	double moveSpeed;
	double rotSpeed;
} TIMING_DATA;


/**
 * struct GAME_WINDOW - contains key SDL objects that acts as our game surface on the screen like the game window, renderer, etc.
 * @window: represents the graphical window on the user's screen
 * @renderer: used to render graphics to @window object
 * @screen_surface: represents a 2D image, used to load, manipulate and
 *		    render images to the screen using @renderer.
 *
 */
typedef struct GAME_WINDOW
{
	SDL_Window *window;
	SDL_Surface *screen_surface;
	SDL_Renderer *renderer;
} GAME_WINDOW;


/**
 * struct RAYCAST_DATA - contains all the data required for raycasting
 *
 * @e: tracks events that has occurred in the system, usually user input
 * @player_data: data type 'PLAYER_DATA'
 * @ray_data: data type 'RAY_DATA'
 * @timing_data: data type 'TIMING_DATA'
 *
 * Description: A combination of the 3 key data structs which were broken down
 *		to simpler bits to be used by the Raycasting Algorithm (DDA).
 */
typedef struct RAYCAST_DATA
{
	int **world_map;
	PLAYER_DATA *player_data;
	RAY_DATA *ray_data;
	TIMING_DATA *timing_data;
	GAME_WINDOW *game_w;
} RAYCAST_DATA;


#endif /* RC_DATA */
