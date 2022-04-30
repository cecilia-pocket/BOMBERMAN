#include "TabPersonnage.h"
#include <cassert>
#include <stdlib.h>
#include <vector>

#include <iostream>
using namespace std;

TabPersonnage::TabPersonnage() {
    nbPerso = 1;
    vector<Personnage> tabPerso;
    tabPerso.resize(nbPerso);
}

TabPersonnage::~TabPersonnage() {
    tabPerso.clear();
}

unsigned int TabPersonnage::getNbPerso() const {
    assert(nbPerso > 0);
    return nbPerso;
}

void TabPersonnage::setNbPerso(unsigned int nouvNbPerso) {
    assert(nouvNbPerso > 0);
    nbPerso = nouvNbPerso;
}

void TabPersonnage::testRegression() {
	assert(getNbPerso() == 1);
	setNbPerso(5);
	assert(getNbPerso() == 5);
}