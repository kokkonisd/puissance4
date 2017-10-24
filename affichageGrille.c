#include <stdio.h>
#include "main.h"
#include "affichageGrille.h"

void afficherCase(int couleur)
{
	switch(couleur) {
		case CASE_JAUNE:
			printf("[%c]", CHAR_JAUNE);
			break;
		case CASE_ROUGE:
			printf("[%c]", CHAR_ROUGE);
			break;
		case CASE_VIDE:
			printf("[%c]", CHAR_VIDE);
			break;
		default:
			printf("ERREUR: \"%d\" n'est pas un code couleur valide.\n", couleur);
	}
}

void afficherGrille(void)
{
	int i, j;
	for (i = DECALAGE; i < (DECALAGE + NB_LIG_GRILLE_VUES); i++) {
		for (j = DECALAGE; j < (DECALAGE + NB_COL_GRILLE_VUES); j++) {
			afficherCase(grille[i][j]);
		}
		printf("\n");
	}
}