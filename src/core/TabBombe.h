/**
  @brief Module gérant un tableau de Bombe
  @file TabBombe.h

  @date 09/03/2021
*/

#ifndef TABBOMBE_H
#define TABBOMBE_H

#include "Bombe.h"
#include <vector>
using namespace std;

class TabBombe {
  private:
    /**
     * @brief
     * Tableau de taille variable de bombes
    */
    vector<Bombe> tabBombe;

    /**
     * @brief
     * Nombre de bombes
    */
    unsigned int nbBombe;

  public:
    /**
     * @brief
     * Constructeur de TabBombe
    */
    TabBombe();

    /**
     * @brief
     * Destructeur de TabBombe
    */
    ~TabBombe();

    /**
     * @brief
     * Accesseur du nombre de Bombes
    */
    unsigned int getNbBombe() const;

    /**
     * @brief
     * Mutateur pour ajouter une nouvelle bombe
     * @param nouvNbBombe : unsigned int
    */
    void setNbBombe(unsigned int nouvNbBombe);
    
    /**
     * @brief
     * Test de regression
    */
    void testRegression();
};

#endif