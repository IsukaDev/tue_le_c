#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define OPEN_ERROR "Impossible d'ouvrir le fichier %s\n"

#define PRODUCT_FORMAT "product:\n\tref_fournisseur: %d\n\tref_sap: %d\n\tdesignation: %s\n\tproduits_par_carton: %d\n\tcode_barre: %ld\n\tprix_achat: %f\n\tprix_vente: %f\n\tmodele: %s\n\tmarque: %s\n\n"

typedef struct {
	int	ref_fournisseur; 
	int	ref_sap;
	char	designation[100];
	int	produits_par_carton;
	long	code_barre;
	double	prix_achat;
	double	prix_vente;
	char	modele[100];
	char	marque[100];
} product_t;

int parse_line(char*, product_t*);

void print_product(product_t);
