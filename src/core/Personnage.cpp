#include "Personnage.h"
#include <cassert>
#include <iostream>
using namespace std;

Personnage::Personnage() {
	posX = posY = 1;
	vitesseX = vitesseY = 1;
	vivant = true;
	coulPerso = Couleur(0,0,0);

	TabBombe bombes;
}

Personnage::Personnage(unsigned int x, unsigned int y) {
	assert(x >= 1 && y >= 1);

	posX = x;
	posY = y;

	vitesseX = vitesseY = 1;
	vivant = true;
	
	coulPerso = Couleur(255,255,255);

	TabBombe bombes;
}

Personnage::~Personnage() {
	vivant = false;
	vitesseX = vitesseY = 0.0;
	posX = posY = 0;
}

bool Personnage::getVivant() const {
	return vivant;
}

void Personnage::setVivant(bool vie) {
	vivant = vie;
}

int Personnage::getPosX() const {
	return posX;
}

int Personnage::getPosY() const {
	return posY;
}

int Personnage::getVitesseX() const {
	return vitesseX;
}

int Personnage::getVitesseY() const {
	return vitesseY;
}

void Personnage::setPosX(const unsigned int &x) {
	assert(posX >= 0);
	posX = x;
}

void Personnage::setPosY(const unsigned int &y) {
	assert(posY >= 0);
	posY = y;
}

void Personnage::setVitesse(const float &x, const float &y) {
	assert(vitesseX > 0 && vitesseY > 0);
	vitesseX = x;
	vitesseY = y;
}

void Personnage::gauche(const Terrain &t) {
	if(t.estPosValid(posX-1,posY)) posX--;
}

void Personnage::droite(const Terrain &t) {
	if(t.estPosValid(posX+1,posY)) posX++;
}

void Personnage::haut(const Terrain &t) {
	if (t.estPosValid(posX,posY+1)) posY++;
}

void Personnage::bas(const Terrain &t) {
	if (t.estPosValid(posX,posY-1)) posY--;
}

void Personnage::testRegression() {
	// Met les position X,Y à 5
	setPosX(5);
	setPosY(5);

	// Vérifie si la position est bien à 5
	assert(getPosX() == 5 && getPosY() == 5);

	// Vérifie si il a une vitesse en X,Y
	assert(vitesseX >= 1 && vitesseY >= 1);

	// Met la vitesse X,Y à 
	setVitesse(5, 5);

	// Vérifie si la vitesse est bien à 
	assert(getVitesseX() == 5 && getVitesseY() == 5);

	// Appel au constructeur Personnage
	Personnage(5, 5);

	// Vérifie si la position est bien à 
	assert(getPosX() == 5 && getPosY() == 5);

	Couleur coul (31, 68, 50);
	
	// Vérification des get
	assert(coul.getRouge() == 31);
	assert(coul.getVert() == 68);
	assert(coul.getBleu() == 50);
	
	coul.setRouge(78);
	coul.setVert(12);
	coul.setBleu(104);

	// Vérifie des get
	assert(coul.getRouge() == 78);
	assert(coul.getVert() == 12);
	assert(coul.getBleu() == 104);

	assert(getVivant() != false);
}