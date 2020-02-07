#include "tue_le_c.h"

int main(int argc, char** argv)
{
	FILE* file = NULL;
	char* line = NULL;
	size_t line_size = 0;
	product_t product;

	file = fopen("data/tue_le_c.csv", "r");

	if (file != NULL) {
		while (getline(&line, &line_size, file) > 0) {
			if(*line != '#') {
				parse_line(line, &product);
				print_product(product);
			}
		}
		free(line);
		fclose(file);
		return 0;
	} else {
		printf(OPEN_ERROR, "data/tue_le_c.csv");
		return 1;
	}
}

int parse_line(char* line, product_t* product) 
{
	char* token;

	token = strtok(line, ",");
	strcpy(product->marque, token);

	token = strtok(NULL, ",");
	strcpy(product->modele, token);

	token = strtok(NULL, ",");
	product->ref_fournisseur = atoi(token);

	token = strtok(NULL, ",");
	product->ref_sap = atoi(token);

	token = strtok(NULL, ",");
	strcpy(product->designation, token);

	token = strtok(NULL, ",");
	product->produits_par_carton = atoi(token);

	token = strtok(NULL, ",");
	product->prix_achat = atof(token);

	token = strtok(NULL, ",");
	product->prix_vente = atof(token);

	token = strtok(NULL, ",\n");
	product->code_barre = atol(token);

	return(0);
}

void print_product(product_t product)
{
	printf(PRODUCT_FORMAT,
			product.ref_fournisseur,
			product.ref_sap,
			product.designation,
			product.produits_par_carton,
			product.code_barre,
			product.prix_achat,
			product.prix_vente,
			product.modele,
			product.marque); 
}
