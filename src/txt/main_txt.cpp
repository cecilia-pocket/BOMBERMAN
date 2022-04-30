#include "winTxt.h"
#include "JeuModeTexte.h"
#include "Jeu.h"

int main ( int argc, char** argv ) {
    termClear();
	Jeu jeu;
	txtBoucle(jeu);
    termClear();
	return 0;
}