#define NB_COL_GRILLE_VUES 7
#define NB_LIG_GRILLE_VUES 6
#define CONFIGURATION_GAGNANTE 4
#define DECALAGE (CONFIGURATION_GAGNANTE - 1)
#define NB_COL_GRILLE_MODELE (NB_COL_GRILLE_VUES + 2 * DECALAGE) 
#define NB_LIG_GRILLE_MODELE (NB_LIG_GRILLE_VUES + 2 * DECALAGE)
#define NB_MAX_COUPS_JEU (NB_LIG_GRILLE_VUES * NB_COL_GRILLE_VUES)

#define CASE_VIDE 0
#define CASE_ROUGE -1
#define CASE_JAUNE 1

// variables
extern int coups_joues;
extern int grille[NB_LIG_GRILLE_MODELE][NB_COL_GRILLE_MODELE];
extern int nb_jetons[NB_COL_GRILLE_VUES];

// fonctions
extern void init (void);