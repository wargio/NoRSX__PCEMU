CC	= g++
CFLAGS	= `sdl-config --cflags` -I"Lib/" -I"./" -I"/usr/include/freetype2/" 
LDLIBS	= `sdl-config --libs` -lfreetype -lSDL_image -I"Lib/"

FILES	=	Lib/Animation Lib/Font Lib/Min  Lib/Objects Lib/Background  Lib/Image  Lib/Msg  Lib/rsxutil Lib/Bitmap  Lib/NoRSX Lib/io/pad Lib/jpgdec/jpgdec Lib/pngdec/pngdec

OBJ 	=	$(addsuffix .o, $(FILES))

FILES	+=	main

all: $(OBJ)
	$(CC) -o NoRSX_EMU $(OBJ) $(LDLIBS)

$(OBJ): %.o: %.cpp
	@echo "CC " $@
	@$(CC) $(CFLAGS) -c -o $@ $<

clean:
	@echo "clean.."
	@rm -rf NoRSX_EMU Lib/*.o Lib/*/*.o *.o Lib/*~ Lib/*/*~ *~
