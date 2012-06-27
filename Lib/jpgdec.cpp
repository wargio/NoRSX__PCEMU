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

#include "jpgdec.h"

void jpgLoadFromFile(const char* filename, jpgData *jpg){
	jpg->surface = IMG_Load(filename);
	jpg->bmp_out = (void*)jpg->surface->pixels;
	jpg->width  = jpg->surface->w;
	jpg->height = jpg->surface->h;
	jpg->pitch  = jpg->surface->pitch;
}

