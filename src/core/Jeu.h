/**
 * @brief Module grant le Jeu
 * @file Jeu.h
 * @date 20/03/2021
*/

#ifndef _JEU_H
#define _JEU_H

#include "Personnage.h"
#include "Terrain.h"

class Jeu {
	private:

        /**
         * @brief terrain
        */
        Terrain ter;

        /**
         * @brief personnage1
        */
        Personnage perso;

        /**
         * @brief personnage2
        */
        Personnage in_perso;

        /**
         * @brief bombe pour personnage1
        */
        Bombe b1;

        /**
         * @brief bombe pour personnage2
        */
        Bombe b2;

        /**
         * @brief tableau de brique
        */
        TabBrique bri;

        /**
         * @brief tableau de bombe
        */
        TabBombe bom;

	public:

        /**
         * @brief constructeur par défaut de la classe jeu
        */
        Jeu();

        /**
         * @brief accesseur : permet d'accéder au terrain
        */
        Terrain& getTerrain();

        /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param i : entier
        */
        Personnage& getPerso(int i);

        /**
         * @brief accesseur : permet d'accéder à une bombe
         * @param j : entier
        */
        Bombe& getBombe(int j);

        /**
         * @brief accesseur : permet d'accéder au terrain
        */
        const Terrain& getConstTerrain() const;

        /**
         * @brief accesseur : permet d'accéder à un personnage
         * @param i : entier
        */
        const Personnage& getConstPerso(int i) const;

        /**
         * @brief accesseur : permet d'accéder à une bombe
         * @param j : entier
        */
        const Bombe& getConstBombe(int j) const;

        /**
         * @brief Fonction qui met à jour les positions de la bombe sur le terrain en fonction du personnage
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void updatePosBombe(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Fonction qui permet l'explosion d'une bombe
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void exploserBombe(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Fonction qui permet de placer une bombe sur le terrain en fonction des positions d'un personnage
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void placerBombe(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Permet de placer et de faire exploser les briques autour d'une bombe
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void placeEtExplose(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Permet de placer et de faire exploser les briques autour d'une bombe
         * @param po : personnage
         * @param ter : terrain
         * @param b : bombe
        */
        void tuerPerso(Personnage& po, Terrain& ter, Bombe& b);

        /**
         * @brief Permet de réaliser une action en appuyant sur une touche du clavier
         * @param touche : caractère
        */
        bool actionClavier(const char touche);
};

#endif
