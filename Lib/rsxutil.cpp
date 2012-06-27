/*
 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

 This program was created by Grazioli Giovanni Dante <wargio@libero.it>.
*/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#include <SDL/SDL.h>

#include "rsxutil.h"
#define flags		SDL_HWSURFACE

#define VERSION		"0.1"

char APP[300];
static SDL_Surface *video;


int flip(){
	SDL_Flip(video);
}


int makeBuffer(rsxBuffer * buffer, u16 width, u16 height, int id){
	SDL_Init(SDL_INIT_EVERYTHING);
	atexit(SDL_Quit);
	video = SDL_SetVideoMode(width, height, 32, flags);
	SDL_Event event;
	sprintf(APP,"NoRSX PS3 EMULATOR - Version %s - %ix%i",VERSION,width, height);
	SDL_WM_SetCaption(APP,APP);
	
	int depth = sizeof(u32);
	int pitch = depth * width;
	int size = depth * width * height;

	buffer->ptr =(uint32_t*) video->pixels;

	if(buffer->ptr == NULL)
		goto error;

	buffer->width = width;
	buffer->height = height;
	buffer->id = id;

	return 0;

 error:

	return -1;
}

int getResolution(u16 *width, u16 *height){
	*width = 720;
	*height = 480;
}

void unint_rsx_emu(){
	SDL_FreeSurface(video);
	SDL_Quit();
}
