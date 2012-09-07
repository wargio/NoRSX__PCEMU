OBJS   =	Lib/Image.cpp Lib/Background.cpp  Lib/rsxutil.cpp Lib/Bitmap.cpp Lib/NoRSX.cpp Lib/Font.cpp Lib/Min.cpp Lib/Objects.cpp Lib/Animation.cpp Lib/Msg.cpp 

#some libs
OBJS  +=	Lib/pngdec/pngdec.cpp Lib/jpgdec/jpgdec.cpp Lib/io/pad.cpp 
#main
OBJS  +=	main.cpp

CC	=  g++
CFLAGS	=  `sdl-config --cflags`
LDLIBS  =  `sdl-config --libs` -lfreetype -lSDL_image -I"Lib/"


all: $(OBJS) 
	$(CC) $(CFLAGS) -o NoRSX_EMU $(OBJS) $(LDLIBS) 

clean:
	-rm -f NoRSX_EMU
