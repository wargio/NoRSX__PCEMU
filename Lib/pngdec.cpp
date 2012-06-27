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

#include "pngdec.h"

void pngLoadFromFile(const char* filename, pngData *png){
	png->surface = IMG_Load(filename);
	png->bmp_out = (void*) png->surface->pixels;
	png->width  = png->surface->w;
	png->height = png->surface->h;
	png->pitch  = png->surface->pitch;
}

