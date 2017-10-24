#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"

bool estCoupInvalide (int colonneJouee)
{
	if (nbDeJetonsColonne(colonneJouee) == NB_LIG_GRILLE_VUES) {
		return true;
	} else {
		return false;
	}
}

int jouerCoupPuissance4 (void)
{
	int choix;

	afficherGrille();

	do {
		printf("Joueur %d> ", (coups_joues % 2) + 1);
		scanf("%d", &choix);
	} while (estCoupInvalide(choix - 1) || (choix <= 0) || (choix > NB_COL_GRILLE_VUES));

	return choix;
}

bool estCoupGagnant (int choixJoueur)
{
	int posX = choixJoueur;
	int posY = NB_LIG_GRILLE_VUES - nbDeJetonsColonne(choixJoueur);
	int absPosX = DECALAGE + choixJoueur;
	int absPosY = DECALAGE + NB_LIG_GRILLE_VUES - nbDeJetonsColonne(choixJoueur);
	int val = demanderCouleurDeLaCaseXY(posX, posY);
	int dist;

	// les entiers du tableau correspondent à :
	// 0 : gauche -> droite
	// 1 : haut -> bas
	// 2 : diagonale-haut-gauche -> diagonale-bas-droite
	// 3 : diagonale-bas-gauche -> diagonale-haut-droite
	int jetons[] = {0, 0, 0, 0};
	int i, j;

	// gauche -> droite
	i = absPosY;
	for (j = absPosX - (CONFIGURATION_GAGNANTE - 1); j <= absPosX + (CONFIGURATION_GAGNANTE - 1); j++) {
		if (grille[i][j] == val) {
			jetons[0]++;
		} else if (jetons[0] < CONFIGURATION_GAGNANTE) {
			jetons[0] = 0;
		}
	}

	// haut -> bas
	j = absPosX;
	for (i = absPosY - (CONFIGURATION_GAGNANTE - 1); i <= absPosY + (CONFIGURATION_GAGNANTE - 1); i++) {
		if (grille[i][j] == val) {
			jetons[1]++;
		} else if (jetons[1] < CONFIGURATION_GAGNANTE) {
			jetons[1] = 0;
		}
	}

	// diagonales
	dist = CONFIGURATION_GAGNANTE - 1;
	i = absPosY;

	// diagonale-haut-gauche -> diagonale-bas-droite
	for (j = absPosX - (CONFIGURATION_GAGNANTE - 1); j <= absPosX + (CONFIGURATION_GAGNANTE - 1); j++) {
		if (grille[i - dist][j] == val) {
			jetons[2]++;
		} else if (jetons[2] < CONFIGURATION_GAGNANTE) {
			jetons[2] = 0;
		}

		dist--;
	}

	// diagonale-bas-gauche -> diagonale-haut-droite
	dist = - (CONFIGURATION_GAGNANTE - 1);
	for (j = absPosX - (CONFIGURATION_GAGNANTE - 1); j <= absPosX + (CONFIGURATION_GAGNANTE - 1); j++) {
		if (grille[i - dist][j] == val) {
			jetons[3]++;
		} else if (jetons[3] < CONFIGURATION_GAGNANTE) {
			jetons[3] = 0;
		}

		dist++;
	}

	for (i = 0; i < 4; i++) {
		if (jetons[i] >= CONFIGURATION_GAGNANTE) {
			return true;
		}
	}

	return false;
}

int jouerPartiePuissance4(void)
{
	bool gagne = false;

	while (coups_joues < NB_MAX_COUPS_JEU) {
		int choix = jouerCoupPuissance4();
		ajouterJeton(choix - 1);
		if (estCoupGagnant(choix - 1)) {
			afficherGrille();
			printf("Joueur %d a gagné !\n", ((coups_joues + 1) % 2) + 1);
			gagne = true;
			break;
		}
	}

	if (!gagne) {
		printf("Fin de partie, la grille est remplie!\n");
	}

	return 0;
}