#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <unistd.h>

// ATTENTION COMPILATION - CREATION DES LIENS VERS LIB MATH 
// commande : gcc main.c -lm -o main
// ---------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 06.10.16
// Description : Estimation de Pi a l'aide de la methode Monte-Carlo
// ---------------------------------------------------------------------------------

int main(){
	// Declaration des variables
	signed long int nb_iteration=0;
	int i; 
	// Nombre de points dans le premier cadran
	int compteur;

	double x,y;
	double z;
	long double pi;

	// Interaction avec l'utlisateur.
	printf("Combien d'iteration voulez utilisez pour essayer de trouver Pi? :\n");
	scanf("%ld", &nb_iteration);

	// Initilisation des nombres aléatoires 
	srand(getpid());
	compteur=0;

	for (i=0; i<nb_iteration; i++){
		// On definie 2 points aléatoirement (x et y)
		x = (double)rand()/RAND_MAX;
		y = (double)rand()/RAND_MAX;

		// Puis on utilse la methode des carrées
		z = x*x+y*y;

		if (z<=1)
			// Si z est plus petit 
			// ou égale a 1 alors on le compte
			compteur++;
	}
	// On applique la formule afin d'obtenir Pi
	pi=(double)compteur/nb_iteration*4;
	
	// On affiche le résultat :
	printf("Nombre(s) d'essai(s) = %ld , estimation de pi est %.10Lg \n", nb_iteration,pi);
	return 0;
}