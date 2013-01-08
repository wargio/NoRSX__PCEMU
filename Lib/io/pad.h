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

#ifndef __IO_PAD_H__
#define __IO_PAD_H__

#define MAX_PADS	127

#define MAX_NEW_PADS	7

#define PAD_INIT	0
#define PAD_STOP	-1

typedef struct {
	int BTN_TRIANGLE;
	int BTN_CIRCLE;
	int BTN_SQUARE;
	int BTN_CROSS;

	int BTN_SELECT;
	int BTN_START;

	int BTN_UP;
	int BTN_DOWN;
	int BTN_LEFT;
	int BTN_RIGHT;

	int BTN_L1;
	int BTN_L2;
	int BTN_L3;

	int BTN_R1;
	int BTN_R2;
	int BTN_R3;

} padData;

typedef struct {
	int button;
	int status[MAX_PADS];
} padInfo;

int ioPadInit(int);
int ioPadEnd();

void ioPadGetInfo(padInfo *PadInfo);
void ioPadGetData(int NumPad, padData *PadData);


#endif
