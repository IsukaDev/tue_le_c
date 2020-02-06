#include <stdlib.h>
#include <stdio.h>

#define OPEN_ERROR "Impossible d'ouvrir le fichier %s\n"

typedef struct {
	int ref_fournisseur; 
	char designation[100];
	int produits_par_carton;
	int code_barre;
	double prix_achat;
	double prix_vente;
	char modele[100];
	char marque[100];
} product;


