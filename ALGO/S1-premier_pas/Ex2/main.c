#include <stdio.h>
// -------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire, compiler et exécuter le programme suivant. 
// Comprenez-vous ce qu’il fait ?
// -------------------------------------------------------------------------------

int main(){

	// Declaration et initialisation des variables
    int i;      /* i : variable de type entier */
    int j;      /* j : variable de type entier */
    i=22;       /* i vaut 22 */
    j=i;        /* donc j vaut aussi 22 à present */

	// Affiche sur la console les valeurs
    printf("i vaut %d\n", i);
    printf("i+j vaut %d\n", i+j);

	// Retour de la fonction :
    return 0;
}
