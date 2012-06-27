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

#include "Lib/NoRSX.h"
#include <time.h>
#include <stdio.h>

static int exitapp, xmbopen;


s32 main(s32 argc, const char* argv[]){
	
	NoRSX *GFX = new NoRSX(RESOLUTION_720x480); //set defined screen resolution You can change it to: 
					             //RESOLUTION_720x480 | RESOLUTION_720x576 | RESOLUTION_1280x720 | RESOLUTION_1920x1080
	Background BG(GFX);
	Object OBJ(GFX);
	Bitmap BMap(GFX);
	Image IMG(GFX);
	MsgDialog K(GFX);

	NoRSX_Bitmap Precalculated_Layer;	
	pngData png;
	BMap.GenerateBitmap(&Precalculated_Layer); //Initialize the Bitmap
	
	Font F2("data/Sans.ttf" ,GFX);  //Loaded from File!

	IMG.LoadPNG("data/NoRSX_Image.png", &png);
	u32 imgX =(GFX->width/2)-(png.width/2), imgY = (GFX->height/2)-(png.height/2);
	
	BG.MonoBitmap(0xb4e83a,&Precalculated_Layer); //a green hex color (you can use hex colors insted of COLOR_XXXXXXX)

	IMG.DrawIMGtoBitmap(imgX,imgY,&png,&Precalculated_Layer);

	OBJ.CircleToBitmap(100,100,50,COLOR_YELLOW,&Precalculated_Layer);

	F2.PrintfToBitmap(10,100,&Precalculated_Layer,COLOR_RED,"Screen %d x %d",GFX->width,GFX->height);
	F2.PrintfToBitmap(10,150,&Precalculated_Layer,COLOR_BLUE, 30,"Press ESC to exit!");
	SDL_Event event;

	exitapp = 1;
	int frame=0;
	while(exitapp){
		static time_t starttime = 0;
		double fps = 0;
		if (starttime == 0) starttime = time (NULL);
		else fps = frame / difftime (time (NULL), starttime);
		while(SDL_PollEvent(&event)){
			if(event.type == SDL_QUIT){
				return 0;
			}
			if( event.type == SDL_KEYDOWN){
				switch( event.key.keysym.sym){
					case SDLK_ESCAPE:{
						goto end;
					}

				}
			}
		}

		BMap.DrawBitmap(&Precalculated_Layer);
		F2.Printf(50,400,"FPS %f", fps);

		GFX->Flip();
		frame ++;
	}
end:
	K.Dialog(MSG_DIALOG_BTN_TYPE_YESNO,"cool MSG Dialog works! Press Y to exit! deroad is cool");

	//You need to clean the Bitmap before exit
	BMap.ClearBitmap(&Precalculated_Layer);

	GFX->NoRSX_Exit();
	return 0;
}

