OBJS   =	Lib/Image.cpp Lib/Background.cpp  Lib/rsxutil.cpp Lib/Bitmap.cpp Lib/NoRSX.cpp Lib/Font.cpp Lib/Min.cpp Lib/Objects.cpp main.cpp  Lib/pngdec.cpp Lib/jpgdec.cpp Lib/Msg.cpp

#OBJS +=	Lib/Msg.cpp

CC	=  g++
CFLAGS	=  `sdl-config --cflags`
LDLIBS  =  `sdl-config --libs` -lfreetype -lSDL_image


all: $(OBJS) 
	$(CC) $(CFLAGS)  -o NoRSX_EMU $(OBJS) $(LDLIBS) 

clean:
	-rm -f NoRSX_EMU
