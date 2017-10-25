#include <stdio.h>
#include "main.h"
#include "affichageGrille.h"

// affiche une seule case avec le couleur specifie en argument
void afficherCase (int couleur)
{
	switch(couleur) {
		case CASE_JAUNE:
			printf("[\e[1;33m%c\e[0m]", CHAR_JAUNE);
			break;
		case CASE_ROUGE:
			printf("[\e[1;31m%c\e[0m]", CHAR_ROUGE);
			break;
		case CASE_VIDE:
			printf("[%c]", CHAR_VIDE);
			break;
		default:
			printf("ERREUR: \"%d\" n'est pas un code couleur valide.\n", couleur);
	}
}

// affiche la grille en entier
void afficherGrille (void)
{
	int i, j;
	for (i = DECALAGE; i < (DECALAGE + NB_LIG_GRILLE_VUES); i++) {
		for (j = DECALAGE; j < (DECALAGE + NB_COL_GRILLE_VUES); j++) {
			afficherCase(grille[i][j]);
		}
		printf("\n");
	}
}