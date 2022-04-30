#include "TabBombe.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabBombe::TabBombe(){
    nbBombe = 1;
    vector<Bombe> tabBombe;
    tabBombe.resize(nbBombe);
}

TabBombe::~TabBombe() {
    tabBombe.clear();
}

unsigned int TabBombe::getNbBombe() const {
    assert(nbBombe > 0);
    return nbBombe;
}

void TabBombe::setNbBombe(unsigned int nouvNbBombe) {
    assert(nouvNbBombe > 0);
    nbBombe = nouvNbBombe;
}

void TabBombe::testRegression() {
    ///////// BOMBE /////////

    Bombe une_bombe(5, 7, 1);

    //Vérification des getPos et de getPortee
    assert(une_bombe.getPosX() == 5);
    assert(une_bombe.getPosY() == 7);

    assert(une_bombe.getPortee() == 1);

    //Vérification du setPortee
    une_bombe.setPortee(3);
    assert(une_bombe.getPortee() == 3);

    ///////// TABBOMBE /////////

    //Vérification getNbBombe
    assert(getNbBombe() == 1);

    //Vérification de setNbBombe
    setNbBombe(4);
    assert(nbBombe == 4);

    //Vérification de la taille du tabBombe
    tabBombe.resize(5);
    assert(tabBombe.size() == 5);

    //Vérification de l'ajout d'une bombe
    tabBombe.push_back(une_bombe);
    assert(tabBombe[5].getPosX() == 5);
    assert(tabBombe[5].getPosY() == 7);
    assert(tabBombe[5].getPortee() == 3);
}