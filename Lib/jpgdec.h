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

#ifndef __JPEGDEC_H__
#define __JPEGDEC_H__

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct {
	void *bmp_out;
	int width,height;
	unsigned int pitch;
	SDL_Surface *surface;
} jpgData;

void jpgLoadFromFile(const char* filename, jpgData *jpg);

#endif
