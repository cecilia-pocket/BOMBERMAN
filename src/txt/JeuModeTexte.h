#ifndef _TXTJEU_H
#define _TXTJEU_H

#include "Jeu.h"
#include "winTxt.h"

/**
 * @brief Boucle du jeu version texte
 * @param j : Jeu
 */
void txtBoucle(Jeu & j);

/**
 * @brief Affichage des différents éléments du jeu
 * @param win : WinTXT
 * @param jeu : Jeu
 */
void txtAff(WinTXT & win, const Jeu & jeu);

#endif
