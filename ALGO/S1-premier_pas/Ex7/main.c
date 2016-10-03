#include <stdio.h>
// ---------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire un algorithme qui demande à l'utilisateur deux entiers puis 
// affiche le signe du produit sans faire la multiplication et le signe de la somme 
// sans faire l'addition.
// ---------------------------------------------------------------------------------

int main(){

	// Declaration et initialisation des valeurs
	int valeur1 = 0;
	int valeur2 = 0;
	
	// En-tete
	printf("------------------------------------\n");
	printf("- Deux entiers                     -\n");
	printf("------------------------------------\n");
	
	// Capture de la première valeur :
	printf("\nVeuillez entrez le premier entier :");
	scanf("%d", &valeur1);

	// Capture de la deuxième valeur :
	printf("\nVeuillez entrez le deuxième entier :");
	scanf("%d", &valeur2);

	// Debut de l'affichage du résultat
	printf("\n------------------------------------\n");
	printf("------------------------------------\n");

	// Affichage des valeurs
	printf("- Voici le produit des deux entiers :");
	printf("\n-> Produit : %d * %d =",valeur1,valeur2);
	printf("\n- Voici l'addition des deux entiers :");
	printf("\n-> Addition : %d + %d =",valeur1,valeur2);

	// Bas de page
	printf("\n----> Aurevoir!                        \n");
	printf("------------------------------------\n");

	// Retour de la fonction :
	return 0;
}