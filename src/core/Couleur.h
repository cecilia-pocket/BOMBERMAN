/**
 * @brief Module gérant la Couleur
 * @file Couleur.h
 * @date 06/03/2021
*/

#ifndef COULEUR_H
#define COULEUR_H

class Couleur {
	private:
		/**
		 * @brief Les composantes d'une couleur
		*/
		unsigned char r, v, b;

	public:
		/**
		 * @brief Les composantes d'une couleur
		*/
		Couleur();

		/**
		 * @brief Initialise la couleur
		 * @param nr : entier
		 * @param nv : entier
		 * @param nb : entier
		*/
		Couleur(unsigned char nr, unsigned char nv, unsigned char nb);

		/**
		 * @brief Accesseur : récupère la composante rouge
		*/
		unsigned char getRouge() const;
	
		/**
		 *  @brief Accesseur : récupère la composante verte
		*/
		unsigned char getVert() const;
	
		/**
		 * @brief Accesseur : récupère la composante bleue
		*/
		unsigned char getBleu() const;
	
		/**
		 * @brief Mutateur : modifie la composante rouge
		 * @param nr : entier
		*/
		void setRouge(unsigned char nr);
	
		/**
		 * @brief Mutateur : modifie la composante verte
		 * @param nv : entier
		*/
		void setVert(unsigned char nv);
	
		/**
		 * @brief Mutateur : modifie la composante bleue du pixel
		 * @param nb : entier
		*/
		void setBleu(unsigned char nb);
};

#endif