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

#include "NoRSX.h"


static int already_done=0;

NoRSX::NoRSX(){
	currentBuffer = 0;
	getResolution(&width,&height);
	for(int i=0;i<2;i++)
		makeBuffer(&buffers[i],width,height,i);
	flip();
}

NoRSX::NoRSX(int id_type){
	id_scr=id_type;
	currentBuffer = 0;
	
	if(id_type==RESOLUTION_1280x720){
		width=1280;height=720;
		buffers[0].width=1280;buffers[0].height=720;
		buffers[1].width=1280;buffers[1].height=720;
	}else if(id_type==RESOLUTION_720x576){
		width=720;height=576;
		buffers[0].width=720;buffers[0].height=576;
		buffers[1].width=720;buffers[1].height=576;
	}else if(id_type==RESOLUTION_720x480){
		width=720;height=480;
		buffers[0].width=720;buffers[0].height=480;
		buffers[1].width=720;buffers[1].height=480;
	}else if(id_type==RESOLUTION_1920x1080){
		width=1920;height=1080;
		buffers[0].width=1920;buffers[0].height=1080;
		buffers[1].width=1920;buffers[1].height=1080;
	}

	for(int i=0;i<2;i++)
		makeBuffer(&buffers[i],width,height,i);
	flip();
}

NoRSX::~NoRSX(){
	if(already_done!=0)
		NoRSX_Exit();
}

void NoRSX::Flip(){
	flip(); // Flip buffer onto screen
}

void NoRSX::NoRSX_Exit(){
	unint_rsx_emu();
	already_done=1;
}

