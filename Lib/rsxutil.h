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

#ifndef __RSXUTIL_H__
#define __RSXUTIL_H__

#include <stdint.h>
#include <SDL/SDL.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

typedef long int s64;
typedef int s32;


typedef struct
{

  int height;
  int width;
  int id;
  uint32_t *ptr;
  // Internal stuff
  uint32_t offset;
} rsxBuffer;


/* Flip a buffer onto the screen. Returns TRUE on success */
int flip();
/* Create a buffer to draw into and assign it to @id. Returns NULL on error */
int makeBuffer (rsxBuffer * buffer, u16 width, u16 height, int id);
/* Get current screen resolution. returns TRUE on success */
int getResolution (u16 *width, u16 *height);
/* Initilize the RSX properly. Returns NULL on error */
void unint_rsx_emu();


#endif /* __RSXUTIL_H__ */
