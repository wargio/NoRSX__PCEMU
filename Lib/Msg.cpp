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

#include "Msg.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define MSG_DIALOG_FONT_SIZE		15

static s32 dialog_action = 0;

static SDL_Event event;

MsgDialog::MsgDialog(Minimum *g){
	G=g;
	F = new Font (COLOR_WHITE, MSG_DIALOG_FONT_SIZE, "Lib/MSG_Dialog.ttf", g);
	bitmap = new uint32_t[(G->width * G->height)];

	s32 size = G->height * G->width;
	for(s32 i = 0; i < size; i++) {
		bitmap[i] = COLOR_BLACK;
	}

	int x = (G->width/8)*G->height;
	for(s32 i = 0; i < G->width; i++){
		bitmap[x+i] = 0x2f1e24;
		bitmap[x+i+G->width] = 0x4d4b50;
		bitmap[x+i+G->width*2] = 0xb7b5ba;
		bitmap[x+i+G->width*3] = 0xccc7cd;
		bitmap[x+i+G->width*4] = 0xcbc5c9;
		bitmap[x+i+G->width*5] = 0x958a90;
		bitmap[x+i+G->width*6] = 0x4c474d;

	}

	x = ((G->height*7/8))*G->width; 
	for(s32 i = 0; i < G->width; i++){
		bitmap[x+i] = 0x2f1e24;
		bitmap[x+i+G->width] = 0x4d4b50;
		bitmap[x+i+G->width*2] = 0xb7b5ba;
		bitmap[x+i+G->width*3] = 0xccc7cd;
		bitmap[x+i+G->width*4] = 0xcbc5c9;
		bitmap[x+i+G->width*5] = 0x958a90;
		bitmap[x+i+G->width*6] = 0x4c474d;
	}

}

MsgDialog::~MsgDialog(){
	free(bitmap);
}

void MsgDialog::Draw_MSG_DIALOG(){
	s32 size = G->buffers[G->currentBuffer].height * G->buffers[G->currentBuffer].width;
	for(s32 i = 0; i < size; i++) {
		G->buffers[G->currentBuffer].ptr[i] = bitmap[i];
	}
}

int MsgDialog::Dialog(msgType md, const char *message){
	dialog_action = 0;
	int y = G->height/2;
	int x = 1*1.*(G->width-(strlen(message)*MSG_DIALOG_FONT_SIZE/2))/2;
	if(strlen(message)>0)
		while(dialog_action == 0){
			Draw_MSG_DIALOG();
			F->Printf(x, y,message);
			while(SDL_PollEvent(&event)){
				if(event.type == SDL_QUIT){
					return 0;
				}

				if(event.type == SDL_KEYDOWN){
					int k = event.key.keysym.sym;
					if(SDLK_RETURN == k && md == MSG_DIALOG_BTN_TYPE_OK){
						dialog_action = MSG_DIALOG_BTN_OK;
						return 1;
					}
					if(SDLK_ESCAPE == k && md == MSG_DIALOG_BTN_TYPE_OK){
						dialog_action = MSG_DIALOG_BTN_ESCAPE;
						return 1;
					}
					if(SDLK_y == k && md == MSG_DIALOG_BTN_TYPE_YESNO){
						dialog_action = MSG_DIALOG_BTN_YES;
						return 1;
					}
					if(SDLK_n == k && md == MSG_DIALOG_BTN_TYPE_YESNO){
						dialog_action = MSG_DIALOG_BTN_NO;
						return 1;
					}
				}

			}
			flip();
		}
/*
	while(1){
		Draw_MSG_DIALOG();
		flip(G->a);
	}
*/
}

int MsgDialog::GetResponse(s32 button){
	if(dialog_action == button){
		return 1;
	}
	return -1;
}


