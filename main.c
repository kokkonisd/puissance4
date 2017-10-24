#include <stdio.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"
#include "jeuPuissance4.h"

int coups_joues;
int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];
int nb_jetons[NB_COL_GRILLE_VUES];

void init (void)
{	
	int i, j;
	
	coups_joues = 0;

	for (i = 0; i < NB_LIG_GRILLE_MODELE; i++) {
		for (j = 0; j < NB_COL_GRILLE_MODELE; j++) {
			grille[i][j] = 0;
		}
	}

	for (i = 0; i < NB_COL_GRILLE_VUES; i++) {
		nb_jetons[i] = 0;
	}
}

int main (void)
{
	jouerPartiePuissance4();
	return 0;	
}
