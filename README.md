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
|   :-------:		|   :---------: |
| w / up arrow		| Move forward  |
| s / down arrow	| Move backward |
| a / left arrown	| Turn left	|
| d / right arrow	| Turn right	|


### Concept
The game was built using the SDL2 library. SDL (The Simple DirectMedia Layer) is a cross-platform development library, desgined to allow access to low level access to access to audio, video, mouse, keyboard and graphics hardware.

### About the Dev

