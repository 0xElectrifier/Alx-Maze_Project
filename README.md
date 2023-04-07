# ELECTRIFIER MAZE

![gif cut from game](/pics/readme_gif.gif)
## Introduction
Electrifier Maze is a simple game built using the Raycasting technique. With a simple objective: attempt to get through the Maze to the other side of the map


## Prerequisites
- Debian/Ubuntu or Fedora OS
- A Bash terminal
- A user with superuser privilege
- git - Click this link and follow the instructions to [install git](https://github.com/git-guides/install-git#install-git-on-linux) on your machine.

This game was built to be compiled and ran on a linux machine only.

## Installation
Using a Bash terminal, run the commands after the `$` sign below.
- Clone the repository

	```bash
	user@user-pc:~/$ git clone https://https://github.com/0xElectrifier/alx-maze_project
	Cloning into 'alx-maze_project'...
	...
	```

- Install SDL2 library on your respective machine

	```bash
	user@user-pc:~/$ ./install_sdl2.sh
	Reading package lists... Done
	Building dependency tree... Done
	Reading state information... Done
	...
	```

- Compile the game files

	```bash
	user@user-pc:~/$ cd alx-maze_project/
	user@user-pc:~/alx-maze_project/$ ./build.sh
	```


### Game controls
| Keys			| Function	|
|  :-------		| :---------	|
| `w` or `up arrow`	| Move forward  |
| `s` or `down arrow`	| Move backward |
| `a` or `left arrown`	| Turn left	|
| `d` or `right arrow`	| Turn right	|


## Concept
- [Raycasting](https://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [SDL2](https://lazyfoo.net/tutorials/SDL/index.php)

	As part of the project requirement, the game was built using the SDL2 library and Raycasting Technique.
	SDL (The Simple DirectMedia Layer) is a cross-platform development library, desgined to allow low level access to audio, video, mouse, keyboard and graphics hardware via OpenGL and Direct3D.
	Raycasting is a rendering technique that creates 3D perspective from a 2D map. The 2D map used in this game is stored in a [file](/map/map1.txt), which is then extracted by a function that reads the file line by line and stores each character in a 2D array representing the length and breadth of the map.


## About the Dev

