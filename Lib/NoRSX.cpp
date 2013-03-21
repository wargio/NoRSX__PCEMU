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
		makeBuffer(&buffers[i],width,height,a);
	flip();
}

NoRSX::NoRSX(int id_type){
	buffer_type = screen_type = id_type;
	currentBuffer = 0;
	
	switch(id_type){
		case RESOLUTION_1920x1080: {
			width=1920;height=1080;
		} break;
		case RESOLUTION_1280x720: {
			width=1280;height=720;
		} break;
		case RESOLUTION_720x576: {
			width=720;height=576;
		} break;
		case RESOLUTION_720x480: {
			width=720;height=480;
		} break;
		default:
			width=720;height=480;
		  break;
	}
	buffers[0].width=width;buffers[0].height=height;
	buffers[1].width=width;buffers[1].height=height;
	buffer = makeMemBuffer(width,height,&buffer_size);

	for(int i=0;i<2;i++)
		makeBuffer(&buffers[i],width,height,a);
	flip();
}

NoRSX::NoRSX(int real_screen_type, int buffer_screen_type){
	screen_type = real_screen_type;
	buffer_type = buffer_screen_type;

	currentBuffer = 0;
	
	switch(real_screen_type){
		case RESOLUTION_1920x1080: {
			width=1920;height=1080;
		} break;
		case RESOLUTION_1280x720: {
			width=1280;height=720;
		} break;
		case RESOLUTION_720x576: {
			width=720;height=576;
		} break;
		case RESOLUTION_720x480: {
			width=720;height=480;
		} break;
		default:
			width=720;height=480;
		  break;
	}
	buffers[0].width=width;buffers[0].height=height;
	buffers[1].width=width;buffers[1].height=height;
	for(int i=0;i<2;i++)
		makeBuffer(&buffers[i],width,height,a);
	
	switch(buffer_screen_type){
		case RESOLUTION_1920x1080:
			width=1920; height=1080;
			break;
		case RESOLUTION_1280x720:
			width=1280; height=720;
			break;
		case RESOLUTION_720x576:
			width=720; height=576;
			break;
		case RESOLUTION_720x480:
			width=720; height=480;
			break;
		default:
			width=720;height=480;
			break;
	}	
	
	buffer = makeMemBuffer(width,height,&buffer_size);
	buffer_size = buffers[0].width * buffers[0].height * sizeof(u32);
	
	flip();
}

NoRSX::~NoRSX(){
	if(already_done!=0)
		NoRSX_Exit();
}

void NoRSX::Flip(){
	memcpy(buffers[currentBuffer].ptr, buffer, buffer_size);
	flip(); // Flip buffer onto screen
}

void NoRSX::RescaleFlip(){
	ResizeBuffer();
	flip();
}

void NoRSX::NoRSX_Exit(){
	unint_rsx_emu();
	free (buffer);
	already_done=1;
}

void NoRSX::ScaleLine(u32 *Target, u32 *Source, u32 SrcWidth, u32 TgtWidth){
 //Thanks to: http://www.compuphase.com/graphic/scale.htm
	int NumPixels = TgtWidth;
	int IntPart = SrcWidth / TgtWidth;
	int FractPart = SrcWidth % TgtWidth;
	int E = 0;

	while (NumPixels-- > 0) {
		*Target++ = *Source;
		Source += IntPart;
		E += FractPart;
		if (E >= (int)TgtWidth) {
			E -= TgtWidth;
			Source++;
		} /* if */
	} /* while */
}

void NoRSX::ResizeBuffer(){
	u32 TgtWidth  = buffers[0].width;
	u32 TgtHeight = buffers[0].height;
	u32 *Target = buffers[currentBuffer].ptr;
	u32 *Source = buffer;
	if(TgtWidth == width && TgtHeight == height){
		memcpy(Target, Source, TgtHeight*TgtWidth*sizeof(u32));
		return;
	}
	int NumPixels = TgtHeight;
	int IntPart = (height / TgtHeight) * width;
	int FractPart = height % TgtHeight;
	int E = 0;
	u32 *PrevSource = NULL;

	while (NumPixels-- > 0) {
		if (Source == PrevSource) {
			memcpy(Target, Target-TgtWidth, TgtWidth*sizeof(*Target));
		} else {
			ScaleLine(Target, Source, width, TgtWidth);
			PrevSource = Source;
		}
		Target += TgtWidth;
		Source += IntPart;
		E += FractPart;
		if (E >= (int)TgtHeight) {
			E -= TgtHeight;
			Source += width;
		}
	}
}

