#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif // WIN32

#include <iostream>
#include "JeuModeTexte.h"


void txtAff(WinTXT & win, const Jeu & jeu) {
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPerso(0);
	const Personnage& in_perso = jeu.getConstPerso(1);

	win.clear();

    // Affichage des murs et des pastilles
	for(int x = 0 ; x < ter.getDimX() ; x++) {
		for(int y = 0 ; y < ter.getDimY() ; y++) {
			win.print(x, y, ter.getXY(x,y));
		}
	}

    // Affichage du joueur 1
	win.print(perso.getPosX(), perso.getPosY(), 'B');
	// Affichage du joueur 2
	win.print(in_perso.getPosX(), in_perso.getPosY(), 'P');
	win.draw();
}

void txtBoucle(Jeu & jeu) {
	// Creation d'une nouvelle fenetre en mode texte
	// => fenetre de dimension et position (WIDTH,HEIGHT,STARTX,STARTY)
    WinTXT win (jeu.getConstTerrain().getDimX(), jeu.getConstTerrain().getDimY());

	bool ok = true;
	int c;
	auto t0 = chrono::system_clock::now();
	auto t2 = chrono::system_clock::now();
	do {
	    txtAff(win,jeu);
		auto t1 = chrono::system_clock::now();
        jeu.getBombe(0).setTempsExplo((t1 - t0).count());
        if(jeu.getBombe(0).getTempsExplo() < 1){
            jeu.exploserBombe(jeu.getPerso(0), jeu.getTerrain(), jeu.getBombe(0));
        }

		auto t3 = chrono::system_clock::now();
        jeu.getBombe(1).setTempsExplo((t3 - t2).count());
        if(jeu.getBombe(1).getTempsExplo() < 1){
            jeu.exploserBombe(jeu.getPerso(1), jeu.getTerrain(), jeu.getBombe(1));
        }

        #ifdef _WIN32
        Sleep(100);
		#else
		usleep(100000);
        #endif // WIN32
		c = win.getCh();
		switch (c) {
			// Commandes du 1er joueur
			case 'k':
				jeu.actionClavier('g');
				break;
			case 'm':
				jeu.actionClavier('d');
				break;
			case 'l':
				jeu.actionClavier('h');
				break;	
			case 'o':
				jeu.actionClavier('b');
				break;
			case 'p':
				if(!jeu.getBombe(0).estSurLeTerrain) {
					jeu.actionClavier('n');
					t0 = t1;
				}
				break;
			case 'c':
				ok = false;
				break;
		// Commandes du 2e joueur
            case 's':
                jeu.actionClavier('v');    // car Y inverse
                break;
            case 'z':
	            jeu.actionClavier('j');     // car Y inverse
                break;
            case 'q':
                jeu.actionClavier('f');
                break;
            case 'd':
                jeu.actionClavier('c');
                break;
            case 'a':
				if(!jeu.getBombe(1).estSurLeTerrain) {
					jeu.actionClavier('u');
					t2 = t3;
				}
                break;
		}
	} while (ok);
}
