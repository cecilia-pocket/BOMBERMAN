#include "Couleur.h"
#include <cassert>

Couleur::Couleur() {
	r = v = b = 0;
}

Couleur::Couleur(unsigned char nr, unsigned char nv, unsigned char nb) {
	r = nr;
	v = nv;
	b = nb;
}

unsigned char Couleur::getRouge() const {
	return r;
}

unsigned char Couleur::getVert() const {
	return v;
}

unsigned char Couleur::getBleu() const {
	return b;
}

void Couleur::setRouge(unsigned char rouge) {
	assert(rouge >= 0);
	r = rouge;
}

void Couleur::setVert(unsigned char vert) {
	assert(vert >= 0);
	v = vert;
}

void Couleur::setBleu(unsigned char bleu) {
	assert(bleu >= 0);
	b = bleu;
}