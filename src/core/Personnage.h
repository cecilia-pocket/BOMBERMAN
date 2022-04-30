 /**
  * @brief Module gérant le Personnage, ainsi que leurs fonctions associées
  * @file Personnage.h
  * @date 06/03/2021
*/

#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Couleur.h"
#include "Terrain.h"
#include "TabBombe.h"
#include <string>

using namespace std;

class Personnage {
	private:

		/**
		 * @brief Couleur R,V,B du personnage
		*/
		Couleur coulPerso;

		/**
		 * @brief Vitesse en X et Y du personnage
		*/
		float vitesseX, vitesseY;

	public:

		/**
		 * @brief Booléen pour savoir si le joueur est en vie
		*/
		bool vivant;

		/**
		 * @brief Position en X et Y du personnage
		*/
		unsigned int posX, posY;

		/**
		 * @brief Tableau de bombes du personnage
		*/

		/**
		 * @brief Les composantes d'une couleur
		*/
		Personnage();

		/**
		 * @brief Création du personnage de l'utilisateur
		 * @param x : entier
		 * @param y : entier
		*/
		Personnage(unsigned int x, unsigned int y);

		/**
		 * @brief Destruction du personnage de l'utilisateur
		*/
		~Personnage();

		/**
		 * @brief Permet de placer une bombe
		*/
	
		/**
		 * @brief Accesseur pour la vie du personnage
		*/
		bool getVivant() const;
		
		/**
		 * @brief Mutateur pour la vie du personnage
		*/
		void setVivant(bool vie);

		/**
		 * @brief Accesseur pour la position en X
		*/
		int getPosX() const;

		/**
		 * @brief Accesseur pour la position en Y
		*/
		int getPosY() const;

		/**
		 * @brief Accesseur pour la vitesse en X
		*/
		int getVitesseX() const;

		/**
		 * @brief Accesseur pour la vitesse en Y
		*/
		int getVitesseY() const;

		/**
		 * @brief Mutateur pour la position en X
		 * @param x : entier
		*/
		void setPosX(const unsigned int &x);

		/**
		 * @brief Mutateur pour la position en Y
		 * @param y : entier
		*/
		void setPosY(const unsigned int &y);

		/**
		 * @brief Mutateur pour la vitesse en X, Y
		 * @param x : entier
		 * @param y : entier
		*/
		void setVitesse(const float &x, const float &y);

		/**
		 * @brief Déplacement du personnage
		 * @param Terrain : classe Terrain
		 * @param x : entier
		*/
		void deplacement();

		/**
		 * @brief Décremente la position en x
		*/
		void gauche(const Terrain &t);

		/**
		 * @brief Incrémente la position en x
		*/
		void droite(const Terrain &t);

		/**
		 * @brief Décremente la position en y
		*/
		void haut(const Terrain &t);

		/**
		 * @brief Décremente la position en y
		*/
		void bas(const Terrain &t);

		/**
		 * @brief
		 * Test de regression
		*/
		void testRegression();
};

#endif