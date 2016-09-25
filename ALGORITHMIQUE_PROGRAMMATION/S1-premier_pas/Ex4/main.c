#include <stdio.h>
// -------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire un programme qui lit 5 entiers et qui donne leur moyenne.
// -------------------------------------------------------------------------------

int main(){

	// Declaration et initialisation des variables
	float note_a, note_b, note_c, note_d, note_e = 0.0;
	float max_note = 5.0;
	float result = 0.0;

	// En-tete
	printf("------------------------------------\n");
	printf("- Calcul de moyenne sur 5 notes    -\n");
	printf("------------------------------------\n");

	// Debut du job
	printf("\nDonnez votre première note : ");
	scanf("%f", &note_a);

	printf("\nDonnez votre deuxième note : ");
	scanf("%f", &note_b);

	printf("\nDonnez votre troisième note : ");
	scanf("%f", &note_c);

	printf("\nDonnez votre quatrième note : ");
	scanf("%f", &note_d);

	printf("\nDonnez votre cinquième note : ");
	scanf("%f", &note_e);

	// Calcul de la moyenne
	result = (note_a+note_b+note_c+note_d+note_e)/max_note;
	
	// Bas de page
	printf("\n------------------------------------\n");
	printf("------------------------------------\n");
	
	// Resultat
	printf("- Votre moyenne est de %f .        \n", result);
	printf("- Aurevoir!                        \n");
	
	printf("------------------------------------\n");

	// Retour de la fonction
	return 0;
}