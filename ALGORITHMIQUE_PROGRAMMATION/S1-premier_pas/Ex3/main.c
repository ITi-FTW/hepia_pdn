#include <stdio.h>
// -------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : La fonction scanf permet de lire une variable introduite depuis 
// le clavier. Notez le & avant la variable (on verra plus tard dans le cours à 
// quoi ça sert) ; "%d" permet de spécifier qu’il s’agit d’un entier. 
// Ecrire ce programme, le compiler et l’exécuter.
// -------------------------------------------------------------------------------

int main(){

	// Declaration et initialisation des variables
	int age = 0;

	// Debut du job
	printf("Quel age avez-vous ?");
	
	// Capture de la valeur
	scanf("%d", &age);

	// Resultat
	printf("Ah ! Vous avez donc %d ans! \n\n", age);

	return 0;
}