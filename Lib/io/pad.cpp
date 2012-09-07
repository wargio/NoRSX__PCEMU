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

#include "pad.h"

#include <SDL/SDL.h>

SDL_Event event;

static int STATUS_PAD = -1;

int ioPadInit(int x){
	STATUS_PAD = PAD_INIT;
	return PAD_INIT;
}

int ioPadEnd(){
	STATUS_PAD = PAD_STOP;
	return PAD_STOP;
}

void ioPadGetInfo(padInfo *PadInfo){
	for(int i=0;i<MAX_PADS;i++)
		PadInfo->status[i] = 1;
}

void ioPadGetData(int NumPad, padData *PadData){
	if(STATUS_PAD == PAD_INIT){
	
		PadData->BTN_TRIANGLE = 0;
		PadData->BTN_CIRCLE = 0;
		PadData->BTN_SQUARE = 0;
		PadData->BTN_CROSS = 0;

		PadData->BTN_SELECT = 0;
		PadData->BTN_START = 0;

		PadData->BTN_UP = 0;
		PadData->BTN_DOWN = 0;
		PadData->BTN_LEFT = 0;
		PadData->BTN_RIGHT = 0;

		PadData->BTN_L1 = 0;
		PadData->BTN_L2 = 0;
		PadData->BTN_L3 = 0;

		PadData->BTN_R1 = 0;
		PadData->BTN_R2 = 0;
		PadData->BTN_R3 = 0;


			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT){
					exit(0);
				}
				else if( event.type == SDL_KEYDOWN){
					switch( event.key.keysym.sym){
						case SDLK_DELETE: {   PadData->BTN_START = 1; break;}
						case SDLK_BACKSPACE: {PadData->BTN_SELECT = 1; break;}

						case SDLK_UP: {    PadData->BTN_UP = 1; break;}
						case SDLK_DOWN: {  PadData->BTN_DOWN = 1; break;}
						case SDLK_LEFT: {  PadData->BTN_LEFT = 1; break;}
						case SDLK_RIGHT: { PadData->BTN_RIGHT = 1; break;}

						case SDLK_LALT: {  PadData->BTN_SQUARE = 1; break;}
						case SDLK_RSHIFT: {PadData->BTN_TRIANGLE = 1; break;}
						case SDLK_ESCAPE: {PadData->BTN_CIRCLE = 1; break;}
						case SDLK_RETURN: {PadData->BTN_CROSS = 1; break;}

						case SDLK_1: {PadData->BTN_R1 = 1; break;}
						case SDLK_2: {PadData->BTN_R2 = 1; break;}
						case SDLK_3: {PadData->BTN_R3 = 1; break;}

						case SDLK_4: {PadData->BTN_L1 = 1; break;}
						case SDLK_5: {PadData->BTN_L2 = 1; break;}
						case SDLK_6: {PadData->BTN_L3 = 1; break;}
					}
				}
			}
	}
}

/*
// △  
#define BTN_TRIANGLE	1;
// ◯  
#define BTN_CIRCLE	2;
// ✕  
#define BTN_SQUARE	3;
// ☐  
#define BTN_CROSS	4;

// SELECT 
#define BTN_SELECT	5;
// START 
#define BTN_START	6;

// ▲   
#define BTN_UP		7;
// ▼  
#define BTN_DOWN	8;
// ◀   
#define BTN_LEFT	9;
// ▶   
#define BTN_RIGHT	10;
*/

