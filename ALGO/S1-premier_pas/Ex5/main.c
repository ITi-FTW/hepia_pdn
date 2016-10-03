#include <stdio.h>
// -------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire un programme qui donne le périmètre et l’aire d’un cercle
// à partir du rayon introduit au clavier par l’utilisateur. Utiliser les float 
// au lieu des int.
// -------------------------------------------------------------------------------

int main(){
	
	// Declaration et initialisation des variables
	float rayon = 0.0;
	float pi = 3.14;
	float result;

	// En-tete
	printf("------------------------------------\n");
	printf("- Calcul du perimetre d'un cercle  -\n");
	printf("------------------------------------\n");

	// Capture de la valeur 
	printf("\nDonnez le rayon : ");
	scanf("%f", &rayon);

	// Calcul du perimetre
	result = 2.0*pi*rayon;
	
	// Bas de page
	printf("\n------------------------------------\n");
	printf("------------------------------------\n");
	
	// Resultat
	printf("- Le perimetre du cercle est de %f .\n", result);
	printf("- Aurevoir!                        \n");
	
	printf("------------------------------------\n");

	// Retour de fonction
	return 0;
}