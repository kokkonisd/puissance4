#include <stdio.h>
#include "main.h"
#include "affichageGrille.h"
#include "manipulationGrille.h"
#include "jeuPuissance4.h"

// compteur de coups joués
int coups_joues;
// la grille (globale) utilisée pour la gestion et l'affichage
int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];
// le compteur des jetons (par colonne)
int nb_jetons[NB_COL_GRILLE_VUES];

// initialiser le jeu
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

// main
int main (void)
{
	init();
	jouerPartiePuissance4();
	return 0;	
}
