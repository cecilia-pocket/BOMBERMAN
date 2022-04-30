#include "TabBrique.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabBrique::TabBrique() {
    nbBrique = 1;
    vector<Brique> tabBrique;
    tabBrique.resize(nbBrique);
}

TabBrique::~TabBrique() {
    nbBrique = 0;
    tabBrique.clear();
}

unsigned int TabBrique::getNbBrique() {
    assert(nbBrique >= 0);
    return nbBrique;
}

void TabBrique::setNbBrique(unsigned int nouvNbBrique) {
    assert(nouvNbBrique >= 0);
    nbBrique = nouvNbBrique;
}

void TabBrique::testRegression() {
    //Vérifie nombre de brique
    assert(getNbBrique() == 1);
    //On set le nombre de brique à 5
    setNbBrique(5);
    //Vérifie si le set a bien été pris en compte
    assert(getNbBrique() == 5);

    Brique bri;
    //Vérification sur la postion de la brique selon le constructeur
    assert(bri.posX == 0 && bri.posY == 0);
    //On set de nouvelles coordonnées
    bri.setPosXY(5,7);
    //Et on les vérifie
    assert(bri.getPosX() == 5 && bri.getPosY() == 7);

    //Vérifie le bonus
    assert(bri.bonus == false);

    //Vérification de la taille du tabBombe
    tabBrique.resize(4);
    assert(tabBrique.size() == 4);
    
    //Vérifications si la brique est détruite
    assert(bri.detruit == false);
    bri.setDetruit(true);
    assert(bri.getDetruit() == true);
}