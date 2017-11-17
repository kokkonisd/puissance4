#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"

char *joueurs[] = { "\e[1;33mJoueur 1\e[0m", "\e[1;31mJoueur 2\e[0m" };

// retourne true si le coup est invalide, false autrement
bool estCoupInvalide (int colonneJouee)
{
	// si la colonne est pleine, le coup est invalide
	if (nbDeJetonsColonne(colonneJouee) == NB_LIG_GRILLE_VUES) {
		return true;
	} else {
		return false;
	}
}

// effectue un tour du jeu
int jouerCoupPuissance4 (void)
{
	int choix;

	afficherGrille();

	// verifier que l'entrée est valide
	do {
		printf("%s> ", joueurs[(coups_joues % 2)]);
		scanf("%d", &choix);
	} while (estCoupInvalide(choix - 1) || (choix <= 0) || (choix > NB_COL_GRILLE_VUES));

	return choix;
}

// retourne true si le coup est gagnant, false autrement
bool estCoupGagnant (int choixJoueur)
{
	// position relative (position dans la grille visible, le point (0,0) se trouve en haut à gauche)
	int posX = choixJoueur;
	int posY = NB_LIG_GRILLE_VUES - nbDeJetonsColonne(choixJoueur);

	// position absolue (position dans la grille globale, le point (0,0) se trouve en haut à gauche)
	int absPosX = DECALAGE + posX;
	int absPosY = DECALAGE + posY;

	// la valeur de la case du dernier coup du jeu
	int val = demanderCouleurDeLaCaseXY(posX, posY);

	/* les entiers du tableau correspondent à :
	0 : gauche -> droite
	1 : haut -> bas
	2 : diagonale-haut-gauche -> diagonale-bas-droite
	3 : diagonale-bas-gauche -> diagonale-haut-droite */
	int jetons[] = { 0, 0, 0, 0 };
	int i;
	
	// pour les diagonales
	int dist = CONFIGURATION_GAGNANTE - 1;
	
	for (i = absPosX - (CONFIGURATION_GAGNANTE - 1); i <= absPosX + (CONFIGURATION_GAGNANTE - 1); i++) {
		// gauche -> droite
		if (grille[absPosY][i] == val) {
			jetons[0]++;

		/* si le nombre des jetons sur la ligne est < à la configuration gagnante
		et on tombe sur un jeton vide ou de couleur different, on réinitialise
		le compteur de la ligne à 0 */
		} else if (jetons[0] < CONFIGURATION_GAGNANTE) {
			jetons[0] = 0;
		}

		// diagonale-haut-gauche -> diagonale-bas-droite
		if (grille[absPosY - dist][i] == val) {
			jetons[2]++;
		} else if (jetons[2] < CONFIGURATION_GAGNANTE) {
			jetons[2] = 0;
		}

		// diagonale-bas-gauche -> diagonale-haut-droite
		if (grille[absPosY + dist][i] == val) {
			jetons[3]++;
		} else if (jetons[3] < CONFIGURATION_GAGNANTE) {
			jetons[3] = 0;
		}

		dist--;
	}

	// haut -> bas
	for (i = absPosY - (CONFIGURATION_GAGNANTE - 1); i <= absPosY + (CONFIGURATION_GAGNANTE - 1); i++) {
		if (grille[i][absPosX] == val) {
			jetons[1]++;
		} else if (jetons[1] < CONFIGURATION_GAGNANTE) {
			jetons[1] = 0;
		}
	}

	/* si une des quatres "lignes" possibles contient
	un nombre de jetons qui est >= à la configuration gagnante,
	alors le coup est un coup gagnant */
	for (i = 0; i < 4; i++) {
		if (jetons[i] >= CONFIGURATION_GAGNANTE) {
			return true;
		}
	}

	/* si aucune ligne ne contient pas assez de jetons, le coup
	n'est pas un coup gagnant */
	return false;
}


// jouer une partie de puissance4
int jouerPartiePuissance4 (void)
{
	/* variable qui détermine si, à la fin de la partie,
	il y avait un coup gagnant ou pas */
	bool gagne = false;

	// tant que la grille n'est pas remplie
	while (coups_joues < NB_MAX_COUPS_JEU) {
		int choix = jouerCoupPuissance4();
		// une fois que la choix est valide, on ajoute le jeton à la grille
		ajouterJeton(choix - 1);
		// si le coup est gagnant
		if (estCoupGagnant(choix - 1)) {
			// on affiche la grille et on annonce le vainqueur
			afficherGrille();
			printf("%s a gagné !\n", joueurs[(coups_joues + 1) % 2]);
			// on a un coup gagnant
			gagne = true;
			// le jeu est terminé
			break;
		}
	}

	// si personne n'a gagné (=la grille est remplie)
	if (!gagne) {
		printf("Fin de partie, la grille est remplie!\n");
	}

	return 0;
}