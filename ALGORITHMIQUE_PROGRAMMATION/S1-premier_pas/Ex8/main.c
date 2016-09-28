#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// ATTENTION COMPILATION - CREATION DES LIENS VERS LIB MATH 
// commande : gcc main.c -lm -o main
// ---------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire un algorithme qui affiche les solutions d’une équation du
// deuxième degré (si elles existent).
// ---------------------------------------------------------------------------------

int main(){

	// Declaration et initialisation des variables
	int a,b,c;
	double d;
	a = 0;
	b = 0;
	c = 0;
	d = 0.0;

	// En-tete
	printf("------------------------------------\n");
	printf("- Equation de deuxieme degre       -\n");
	printf("------------------------------------\n");

	printf("\n- Calcul d'une equation sous la forme ax^2 + bx + c = 0\n");

	// Capture des valeurs
	printf("\n- Introduisez la valeur pour a :");
	scanf("%d", &a);

	printf("\n- Introduisez la valeur pour b :");
	scanf("%d", &b);

	printf("\n- Introduisez la valeur pour c :");
	scanf("%d", &c);

	// Calcul du descriminant (b^2-4ac)
	d = pow(b,2) - 4.0*a*c;

	// Distinction des differents cas
	
	// Cas : 0x = 0
	if (a==0 && b==0 && c==0){
		printf("------------------------------------\n");
		printf("Tous les nombres peuvent être une solution dans cette équation.\n");
		printf("------------------------------------\n");
	}
	// Contradiction :
	// c # 0 et c = 0
	else if (a==0 && b==0){
		printf("------------------------------------\n");
		printf("Cette equation ne posède pas de solutions.\n");
		printf("------------------------------------\n");
	}
	// bx + c = 0 
	else if (a==0){
		printf("------------------------------------\n");
		printf("La solution de cette equation du premier degre est :\n");
		// Cast de la valeur a la volée
		printf("x = %4f\n", (double)c/b);
		printf("------------------------------------\n");
	}
	// b^2-4ac < 0 
	else if (d<0){
		printf("------------------------------------\n");
		printf("Cette solution n'as de solution.\n");
		printf("------------------------------------\n");
	}
	// b^2-4ac = 0
	else if (d==0){
		printf("------------------------------------\n");
		printf("Cette équation à une solution possible :\n");
		// Attention au parentheses (orde operations)
		printf("x = %4f\n", (double)-b/(2*a));
		printf("------------------------------------\n");
	}
	// b^2-4ac > 0
	else {
		printf("------------------------------------\n");
		printf("Les solutions pour cette équations sont :\n");
		// Deux solutions possibles (Formule de Viet)
		printf("x1 = %4f\n", (-b+sqrt(d))/(2*a));
		printf("x2 = %4f\n", (-b-sqrt(d))/(2*a));
		printf("------------------------------------\n");
	}

	// ATTENTION COMPILATION - CREATION DES LIENS VERS LIB MATH 
	// commande : gcc main.c -lm -o main

	// Retour de la fonction
	return 0;
}