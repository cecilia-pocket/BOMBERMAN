#include "Jeu.h"
#include <iostream>
#include <unistd.h>
#include <chrono>
using namespace std;
Jeu::Jeu () : ter(), perso(), in_perso(13,9), b1(), b2(), bom() {
}

Terrain& Jeu::getTerrain() { return ter; }

Personnage& Jeu::getPerso(int i) {
	if( i == 0){
		return perso; 
	}
	if( i == 1){
		return in_perso;
	}
}

Bombe& Jeu::getBombe(int j) { 
	if( j == 0){
		return b1; 
	}
	if( j == 1){
		return b2;
	}
}

const Terrain& Jeu::getConstTerrain() const { return ter; }

const Personnage& Jeu::getConstPerso(int i) const { 
	if( i == 0) {
		return perso; 
	}
	if( i == 1) {
		return in_perso;
	}
}

const Bombe& Jeu::getConstBombe(int j) const { 
	if( j == 0){
		return b1; 
	}
	if( j == 1){
		return b2;
	}
}

void Jeu::placerBombe(Personnage& po, Terrain& ter, Bombe& b) {
	//on place la bombe aux coordonnées du perso
	ter.placer(po.getPosX(), po.getPosY());
	b.estSurLeTerrain = true;
}

void Jeu::updatePosBombe(Personnage& po, Terrain& ter, Bombe& b) {
	//update des positions de la bombe
	b.setPos(po.getPosX(), po.getPosY());
}

void Jeu::exploserBombe(Personnage& po, Terrain& ter, Bombe& b) { 
	ter.estExplosee(b.getPosX() + b.getPortee(), b.getPosY());
	ter.estExplosee(b.getPosX() - b.getPortee(), b.getPosY());
	ter.estExplosee(b.getPosX(), b.getPosY() - b.getPortee());
	ter.estExplosee(b.getPosX(), b.getPosY() + b.getPortee());
	ter.bombeEstExplosee(b.getPosX(), b.getPosY());	
	b.estSurLeTerrain = false;				
}

void Jeu::tuerPerso(Personnage& po, Terrain& ter, Bombe& b) {
	if( (po.getPosX() == b.getPosX() + b.getPortee() && po.getPosY() == b.getPosY()) || 
		(po.getPosX() == b.getPosX() - b.getPortee() && po.getPosY() == b.getPosY()) ||
		(po.getPosY() == b.getPosY() + b.getPortee() && po.getPosX() == b.getPosX()) || 
		(po.getPosY() == b.getPosY() - b.getPortee() && po.getPosX() == b.getPosX()) || 
		(po.getPosX() == b.getPosX() && po.getPosY() == b.getPosY())) 
	{
		po.vivant = false;	
	}
}

bool Jeu::actionClavier(const char touche) {
	switch(touche) {
		// Commandes du 1er joueur
		case 'g' :
			perso.gauche(ter);
			break;
		case 'd' :
			perso.droite(ter);
			break;
		case 'h' :
			perso.haut(ter);
			break;
		case 'b' :
			perso.bas(ter);
			break;
		case 'n' :
			placerBombe(perso, ter, b1);
			updatePosBombe(perso, ter, b1);
			break;
		// Commandes du 2e joueurs
		case 'f' :
			in_perso.gauche(ter);
			break;
		case 'c' :
			in_perso.droite(ter);
			break;
		case 'v' :
			in_perso.haut(ter);
			break;
		case 'j' :
			in_perso.bas(ter);
			break;
		case 'u' :
			placerBombe(in_perso, ter, b2);
			updatePosBombe(in_perso, ter, b2);
			break;
	}
	return false;
}