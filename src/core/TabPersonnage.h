/**
  @brief Module gérant un tableau de Personnage
  @file TabPersonnage.h

  @date 09/03/2021
*/

#ifndef TABPERSONNAGE_H
#define TABPERSONNAGE_H

#include "Personnage.h"
#include <vector>
using namespace std;

class TabPersonnage {
  private:
    /**
      * @brief
      * Tableau de taille variable de bombes
    */
    vector<Personnage> tabPerso;

    /**
     * @brief
     * Nombre de joueur
    */
    unsigned int nbPerso;

  public:
    /**
     * @brief
     * Constructeur de TabPerso
    */
    TabPersonnage();

    /**
     * @brief
     * Destructeur de TabPerso
    */
    ~TabPersonnage();

    /**
     * @brief
     * Accesseur du nombre de joueur
    */
    unsigned int getNbPerso() const;

    /**
     * @brief
     * Mutateur pour ajouter un nouveau joueur
     * @param nouvNbBombe : unsigned int
    */
    void setNbPerso(unsigned int nouvNbPerso);
    
    /**
     * @brief
     * Test de regression
    */
    void testRegression();
};

#endif