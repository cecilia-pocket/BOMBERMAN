CC = g++
FLAGS = -ggdb -Wall

ALLOBJ= ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o ./obj/Jeu.o

CORE = ./src/core/Terrain.cpp ./src/core/Jeu.cpp ./src/core/Couleur.cpp ./src/core/Personnage.cpp ./src/core/TabPersonnage.cpp ./src/core/Brique.cpp ./src/core/TabBrique.cpp ./src/core/Bombe.cpp ./src/core/TabBombe.cpp

SRCS_TXT = $(CORE) ./src/txt/JeuModeTexte.cpp ./src/txt/winTxt.cpp ./src/txt/main_txt.cpp

LIB = -Isrc -Isrc/core -Isrc/sdl2 -Itxt

ifeq ($(OS), Windows_NT)
	INCLUDE_DIR_SDL = 	-Iextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/include/SDL2/ \
			-Iextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/include/SDL2/

	LIBS_SDL = -Lextern \
			-Lextern/SDL2_mingw-cb20/SDL2-2.0.12/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_ttf-2.0.15/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_image-2.0.5/x86_64-w64-mingw32/lib \
			-Lextern/SDL2_mingw-cb20/SDL2_mixer-2.0.4/x86_64-w64-mingw32/lib \
			-lmingw32 -lSDL2main -lSDL2.dll -lSDL2_ttf.dll -lSDL2_image.dll -lSDL2_mixer.dll

else
INCLUDE_DIR_SDL = -I/usr/include/SDL2
LIBS_SDL = -lSDL2 -lSDL2_ttf -lSDL2_image -lSDL2_mixer
endif

all: ./bin/Test ./bin/mainTXT ./bin/mainSDL

./bin/Test: ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/Terrain.o ./obj/TabPersonnage.o
	$(CC) $(FLAGS) ./obj/Test.o ./obj/Couleur.o ./obj/Brique.o ./obj/TabBrique.o ./obj/Bombe.o ./obj/TabBombe.o ./obj/Personnage.o ./obj/TabPersonnage.o ./obj/Terrain.o -o ./bin/Test.exe

./obj/Test.o: ./src/Test.cpp ./src/core/Couleur.h ./src/core/Brique.h ./src/core/TabBrique.h ./src/core/Bombe.h ./src/core/TabBombe.h  ./src/core/Personnage.h ./src/core/TabPersonnage.h
	$(CC) $(FLAGS) $(LIB) -c ./src/Test.cpp -o ./obj/Test.o

# ----------------------------------------------------- #

./obj/Couleur.o: ./src/core/Couleur.cpp ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Couleur.cpp -o ./obj/Couleur.o

./obj/Personnage.o: ./src/core/Personnage.cpp ./src/core/Personnage.h ./src/core/Terrain.h ./src/core/TabBombe.h ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Personnage.cpp -o ./obj/Personnage.o

./obj/TabPersonnage.o: ./src/core/TabPersonnage.cpp ./src/core/TabPersonnage.h ./src/core/Personnage.h
	$(CC) $(FLAGS) -c ./src/core/TabPersonnage.cpp -o ./obj/TabPersonnage.o

./obj/Brique.o: ./src/core/Brique.cpp ./src/core/Brique.h ./src/core/Couleur.h
	$(CC) $(FLAGS) -c ./src/core/Brique.cpp -o ./obj/Brique.o

./obj/TabBrique.o: ./src/core/TabBrique.cpp ./src/core/TabBrique.h ./src/core/Brique.h
	$(CC) $(FLAGS) -c ./src/core/TabBrique.cpp -o ./obj/TabBrique.o

./obj/Bombe.o: ./src/core/Bombe.cpp ./src/core/Bombe.h
	$(CC) $(FLAGS) -c ./src/core/Bombe.cpp -o ./obj/Bombe.o

./obj/TabBombe.o: ./src/core/TabBombe.cpp ./src/core/TabBombe.h ./src/core/Bombe.h
	$(CC) $(FLAGS) -c ./src/core/TabBombe.cpp -o ./obj/TabBombe.o

./obj/Terrain.o: ./src/core/Terrain.cpp ./src/core/Terrain.h
	$(CC) $(FLAGS) -c ./src/core/Terrain.cpp -o ./obj/Terrain.o

# ----------------------------------------------------- #

./bin/mainTXT: ./obj/main_txt.o ./obj/winTxt.o ./obj/JeuModeTexte.o $(ALLOBJ)
	$(CC) $(FLAGS) $(ALLOBJ) ./obj/main_txt.o ./obj/winTxt.o ./obj/JeuModeTexte.o -o ./bin/mainTXT

./obj/main_txt.o: ./src/txt/main_txt.cpp ./src/txt/winTxt.h ./src/txt/JeuModeTexte.h ./src/core/Jeu.h
	$(CC) $(FLAGS) -c ./src/txt/main_txt.cpp $(LIB) -o ./obj/main_txt.o

./obj/JeuModeTexte.o: ./src/txt/JeuModeTexte.cpp ./src/txt/JeuModeTexte.h ./src/txt/winTxt.h ./src/core/Jeu.h
	$(CC) $(FLAGS) -c ./src/txt/JeuModeTexte.cpp $(LIB) -o ./obj/JeuModeTexte.o

./obj/winTxt.o: ./src/txt/winTxt.cpp ./src/txt/winTxt.h
	$(CC) $(FLAGS) -c ./src/txt/winTxt.cpp -o ./obj/winTxt.o

./obj/Jeu.o: ./src/core/Jeu.cpp ./src/core/Jeu.h ./src/core/Personnage.h ./src/core/Terrain.h
	$(CC) $(FLAGS) -c ./src/core/Jeu.cpp -o ./obj/Jeu.o

# ----------------------------------------------------- #

./bin/mainSDL: ./obj/main_SDL.o $(ALLOBJ) ./obj/sdlJeu.o
	$(CC) $(FLAGS) $(ALLOBJ) ./obj/sdlJeu.o ./obj/main_SDL.o -o ./bin/mainSDL $(LIBS_SDL)

./obj/sdlJeu.o: ./src/sdl2/sdlJeu.h ./src/sdl2/sdlJeu.cpp ./src/core/Jeu.cpp
	$(CC) $(FLAGS) -c ./src/sdl2/sdlJeu.cpp $(INCLUDE_DIR_SDL) $(LIB) -o ./obj/sdlJeu.o

./obj/main_SDL.o: ./src/sdl2/main_SDL.cpp ./src/sdl2/sdlJeu.h
	$(CC) $(FLAGS) -c ./src/sdl2/main_SDL.cpp $(INCLUDE_DIR_SDL) $(LIB) -o ./obj/main_SDL.o

# ----------------------------------------------------- #

doc:
	doxygen -g doc/image.doxy

clean:
ifeq ($(OS), Windows_NT)
	del .\obj\*.o
	del .\bin\*.exe
else
	rm ./obj/*.o ./bin/main*
endif