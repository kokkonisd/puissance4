#include <stdio.h>
#include "main.h"

/* retourne le couleur de la case (absVue, ordVue),
où absVue, ordVue sont des coordonnées RELATIVES à la
partie visible de la grille */
int demanderCouleurDeLaCaseXY (int absVue, int ordVue)
{
	return grille[DECALAGE + ordVue][DECALAGE + absVue];
}

// retourne le nombre de jetons par colonne (getter)
int nbDeJetonsColonne (int numColonne)
{
	return nb_jetons[numColonne];
}

// ajoute un jeton à la grille
void ajouterJeton (int choixJoueur)
{
	int jeton;

	// les jaunes commencent
	if (coups_joues % 2 == 0) {
		jeton = CASE_JAUNE;
	} else {
		jeton = CASE_ROUGE;
	}

	// prendre en compte le décalage, et ajouter le jeton dans la grille visible
	grille[DECALAGE + NB_LIG_GRILLE_VUES - nbDeJetonsColonne(choixJoueur) - 1][DECALAGE + choixJoueur] = jeton;

	// mettre à jour le compteur de jetons et celui des coups joués
	nb_jetons[choixJoueur]++;
	coups_joues++;
}