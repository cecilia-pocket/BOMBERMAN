/**
  @brief Module gérant une Bombe
  @file Bombe.h
  @date 09/03/2021
*/

#ifndef BOMBE_H
#define BOMBE_H

#include <chrono>

class Bombe {
  private:
    /**
     * @brief Position de la bombe
    */
    unsigned int posX, posY;

    /**
     * @brief Portée de la bombe
    */
    int portee;

  public:
    /**
     * @brief Temps avant l'explosion de la bombe
    */
    unsigned int tempsExplosion;

    /**
     * @brief Booléen vrai si la bombe est sur le terrain
    */
    bool estSurLeTerrain;

    /**
     * @brief Constructeur par défaut de la classe : initialise la position à 0 et la portée à 0
    */
    Bombe();

    /**
     * @brief Constructeur de la classe : initialise la position avec positionX, positionY et la portée avec nouvPortee
     * @param positionX : unsigned int
     * @param positionY : unsigned int
     * @param nouvPortee : int 
    */
    Bombe(unsigned int positionX, unsigned int positionY, int nouvPortee);

    /**
     * @brief Accesseur : récupère la position X de la bombe
    */
    unsigned int getPosX() const;

    /**
     * @brief Accesseur : récupère la position Y de la bombe
    */
    unsigned int getPosY() const;

    /**
     * @brief Mutateur : modifie la position de la bombe
     * @param x : unsigned int
     * @param y : unsigned int
    */
    void setPos(unsigned int x, unsigned int y);

    /**
     * @brief Accesseur : récupère la portée de la bombe
    */
    int getPortee() const;

    /**
     * @brief Mutateur : modifie la portée de la bombe
     * @param p : int
    */
    void setPortee(int p);

    /**
     * @brief Accesseur : accède au temps d'explosion de la bombe
    */
    int getTempsExplo();

    /**
     * @brief Mutateur : modifie le temps d'explosion de la bombe
     * @param p : int
    */
    void setTempsExplo(int t);

    /**
     * @brief Fonction qui définit un compteur
    */
    void compteurExplo(); 
};

#endif