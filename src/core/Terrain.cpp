#include "Terrain.h"
#include <cassert>

using namespace std;
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

const char terrain2[11][16] = {
"###############",
"#  .........  #",
"# #.#.#.#.#.# #",
"#.............#",
"#.#.#.#.#.#.#.#",
"#.............#",
"#.#.#.#.#.#.#.#",
"#.............#",
"# #.#.#.#.#.# #",
"#  .........  #",
"###############"
};

#ifdef _WIN32
void Terrain::showConsoleCursor(bool showFlag)
{
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO	cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag; 
    SetConsoleCursorInfo(out, &cursorInfo);
}
#endif 

Terrain::Terrain() {
	dimX = 15;
	dimY = 11;
	#ifdef _WIN32
	showConsoleCursor(false);
	#endif 
	for(unsigned int x = 0 ; x < dimX ; x++) {
		for(unsigned int y = 0 ; y < dimY ; y++) {
			ter[x][y] = terrain2[dimY-1-y][x];
		}
	}
}

void Terrain::placer(unsigned int x, unsigned int y) {
	assert(x>=0);
    assert(y>=0);
    assert(x<dimX);
    assert(y<dimY);
    ter[x][y]='o';
}

void Terrain::bombeEstExplosee(unsigned int x, unsigned int y) {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimX);
	assert(y<dimY);
	if(ter[x][y] == 'o'){
		ter[x][y] = ' ';
	}
}	

void Terrain::estExplosee(unsigned int x, unsigned int y) {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimX);
	assert(y<dimY);
	if(ter[x][y] != '#') {
		ter[x][y] = ' ';
	}
}

void Terrain::estTuee(unsigned int x, unsigned int y) {
	assert(x>=0);
	assert(y>=0);
	assert(x<dimX);
	assert(y<dimY);
	if(ter[x][y] == 'B' || ter[x][y] == 'P') {
		ter[x][y] = ' ';
	}
}

bool Terrain::estPosValid(const unsigned int x, const unsigned int y) const {
	return ( (x >= 0) && (x < dimX) && (y >= 0) && (y < dimY) && (ter[x][y] != '#') && (ter[x][y] != '.') && (ter[x][y] != 'o') );
}

char Terrain::getXY(const unsigned int x, const unsigned int y) const {
	assert(x >= 0);
	assert(y >= 0);
	assert(x < dimX);
	assert(y < dimY);

	return ter[x][y];
}

int Terrain::getDimX() const {
	return dimX;
}

int Terrain::getDimY() const {
	return dimY;
}