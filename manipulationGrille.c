#include <stdio.h>
#include "main.h"

int demanderCouleurDeLaCaseXY (int absVue, int ordVue)
{
	return grille[DECALAGE + ordVue][DECALAGE + absVue];
}

int nbDeJetonsColonne (int numColonne)
{
	return nb_jetons[numColonne];
}

void ajouterJeton(int choixJoueur)
{
	int jeton;

	// les jaunes commencent
	if (coups_joues % 2 == 0) {
		jeton = CASE_JAUNE;
	} else {
		jeton = CASE_ROUGE;
	}

	grille[DECALAGE + NB_LIG_GRILLE_VUES - nbDeJetonsColonne(choixJoueur) - 1][DECALAGE + choixJoueur] = jeton;

	nb_jetons[choixJoueur]++;
	coups_joues++;
}