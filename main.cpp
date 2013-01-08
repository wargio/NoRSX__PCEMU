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

#include <NoRSX.h>
#include <time.h>
#include <stdio.h>

#include <io/pad.h>

static int exitapp, xmbopen;


s32 main(s32 argc, const char* argv[]){

	padData paddata;
	padInfo padinfo;

	ioPadInit(7);

	
	NoRSX *GFX = new NoRSX(RESOLUTION_1280x720); //set defined screen resolution You can change it to: 
					             //RESOLUTION_720x480 | RESOLUTION_720x576 | RESOLUTION_1280x720 | RESOLUTION_1920x1080
	Background BG(GFX);
	Object OBJ(GFX);
	Bitmap BMap(GFX);
	Image IMG(GFX);
	MsgDialog K(GFX);
//	Animation An(GFX); //animation

//	NoRSX_Animation TestAni; //define an animation struct

//	An.LoadAnimation(11,50,100,&ani,&TestAni); //Load the animation struct by saying (Frame_max_num, frame_width, frame_height, ChromaKey, pngData* or jpgData*, NoRSX_Animation *);

	NoRSX_Bitmap Precalculated_Layer;	
	pngData *png = new pngData;
	BMap.GenerateBitmap(&Precalculated_Layer); //Initialize the Bitmap
	
	Font F2("data/Sans.ttf" ,GFX);  //Loaded from File!

	IMG.LoadPNG("data/NoRSX_Image.png", png);
	png = IMG.ResizeImage(png, 500, 500); //ResizeImage(pngData*, new width, new height)

	u32 imgX =(GFX->width/2)-( png->width/2), imgY = (GFX->height/2)-( png->height/2);
	
	BG.MonoBitmap(0xb4e83a,&Precalculated_Layer); //a green hex color (you can use hex colors insted of COLOR_XXXXXXX)

	IMG.DrawIMGtoBitmap(imgX,imgY,png,&Precalculated_Layer);

	OBJ.CircleToBitmap(100,100,50,COLOR_YELLOW,&Precalculated_Layer);

	F2.PrintfToBitmap(10,100,&Precalculated_Layer,COLOR_RED,"Screen %d x %d",GFX->width,GFX->height);
	F2.PrintfToBitmap(10,150,&Precalculated_Layer,COLOR_BLUE, 30,"Press ESC to exit!");

	exitapp = 1;
	int frame=0;
	while(exitapp){
		static time_t starttime = 0;
		double fps = 0;
		if (starttime == 0) starttime = time (NULL);
		else fps = frame / difftime (time (NULL), starttime);

		ioPadGetInfo(&padinfo);
		for(int i=0;i<MAX_PADS;i++){
			if(padinfo.status[i]){
				ioPadGetData(i,&paddata);
				if(paddata.BTN_CROSS){        //ENTER
					goto end;
				}
				else if(paddata.BTN_CIRCLE){  //ESC
					goto end;
				}
			}
		}
/*
		if(frame%6==0){
			frame_an++;
			if(frame_an>9 || frame_an <0)
				frame_an = 0;
		}
*/
		BMap.DrawBitmap(&Precalculated_Layer);
		F2.Printf(50,400,0,30,"FPS %.2f", fps);
	//	An.AlphaDrawAnimation(100,250,frame_an, &TestAni); //draw the frame (x,y,frame_number, NoRSX_Animation *);

		GFX->Flip();
		frame ++;
	}
end:

	//You need to clean the Bitmap before exit
	BMap.ClearBitmap(&Precalculated_Layer);

	//You need to clean the Animation before exit
//	An.CleanAnimation(&TestAni);

	GFX->NoRSX_Exit();
	ioPadEnd();
	return 0;
}


