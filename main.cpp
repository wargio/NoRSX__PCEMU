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

/*
MSG Dialog is not ready to be released
*/

s32 main(s32 argc, const char* argv[]){
	
	NoRSX *GFX = new NoRSX(); //set defined screen resolution You can change it to: 
					             //RESOLUTION_720x480 | RESOLUTION_720x576 | RESOLUTION_1280x720 | RESOLUTION_1920x1080
	Background BG(GFX);
	Object OBJ(GFX);
	Bitmap BMap(GFX);
	Image IMG(GFX);

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
			if(event.type == SDL_KEYDOWN){
				switch( event.key.keysym.sym){
					case SDLK_RETURN: return 1;
					case SDLK_ESCAPE:{
						return 1;
						break;
					}
				}
			}
		}

		BMap.DrawBitmap(&Precalculated_Layer);
/*		BG.Mono(0xb4e83a); //a green hex color (you can use hex colors insted of COLOR_XXXXXXX)
		IMG.DrawIMG(imgX,imgY,&png);
		OBJ.Circle(500,500,50,COLOR_YELLOW);

		F1.Printf(150,200,COLOR_RED,"Screen %d x %d",GFX->width,GFX->height);
		F1.Printf(150,250,COLOR_BLUE, 35,"Press X to exit!");
		F1.Printf(150,100,"FPS %f", fps);
		F2.Printf(150,300,COLOR_GREEN,20,"FreeType2 with TTF support :)");
*/
		F2.Printf(50,400,"FPS %f", fps);

		GFX->Flip();
		frame ++;
	}

	//You need to clean the Bitmap before exit
	BMap.ClearBitmap(&Precalculated_Layer);

	GFX->NoRSX_Exit();
	return 0;
}

