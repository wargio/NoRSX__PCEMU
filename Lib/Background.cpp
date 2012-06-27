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

#include "Background.h"
#include <math.h>

Background::Background(Minimum *g){
	G=g;
	frame=0;
}

void Background::Mono(s32 Color){
	s32 size = G->buffers[G->currentBuffer].height * G->buffers[G->currentBuffer].width;
	for(s32 i = 0; i < size; i++){
		G->buffers[G->currentBuffer].ptr[i] = Color;
	}
}

void Background::MonoBitmap(s32 Color, NoRSX_Bitmap *a){
	s32 size = G->buffers[G->currentBuffer].height * G->buffers[G->currentBuffer].width;
	for(s32 i = 0; i < size; i++) {
		a->bitmap[i] = Color;
	}
}

void Background::UpDownGradient(s32 Color1, s32 Color2){
	s32 size = G->buffers[G->currentBuffer].height * G->buffers[G->currentBuffer].width;
	for(s32 i = 0; i < size; i++){
		s32 Color = Color1*i/100 + Color2*(100-i)/100;
		G->buffers[G->currentBuffer].ptr[i] = Color;
	}
}

void Background::UpDownGradientBitmap(s32 Color1, s32 Color2, NoRSX_Bitmap *a){
	s32 size = G->buffers[G->currentBuffer].height * G->buffers[G->currentBuffer].width;
	s32 Color = Color1+ Color2;
	for(s32 i = 0; i < size; i++){
		a->bitmap[i] = Color;
		if(i%(size/1000)==0) Color = Color1*(i%size) + Color2*(i%size);
	}
}



