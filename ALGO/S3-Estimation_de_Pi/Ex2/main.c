#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// ATTENTION COMPILATION - CREATION DES LIENS VERS LIB MATH 
// commande : gcc main.c -lm -o main
// ---------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 06.10.16
// Description : Estimation a l'aide de serie numériques
// ---------------------------------------------------------------------------------

int main(){
	float tot = 0;

	for (int i=1 ; i <= 90; i++){

		tot += pow(-1,i+1)/(i*i);

		printf("Ma verif : %f\n", sqrt(12*tot));
		printf("Mon total vaut :%f\n", tot);
	}

	return 0;
}