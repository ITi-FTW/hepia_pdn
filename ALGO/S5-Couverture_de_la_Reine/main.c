/*********************************************************************
 Auteur : José Gonçalves
 Date : 06.10.16
 Description : Couverture de la reine
**********************************************************************/

#include <stdlib.h>
#include <stdio.h>

// Couleurs pour le terminal
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

/* Creation du tableau de l'echequier */
int limite = 8;
int array[8];
int cpt_sol = 0;

/* Print de l'echequier */
void AfficheEchequier(){
  	// Declaration des variables
	int i,j;

	// Création de l'echequier
  	printf(COLOR_BLUE"+------------------------+\n");

  	for ( i = 0 ; i < limite; i++) {
    	printf (COLOR_BLUE "|");
    	for (j = 0 ; j < limite; j++){
    		if (j == array[i]){
    	  		printf(COLOR_RED " R ");
    	  	}
    	  	else {
    	  		// On print des cases vides
    	  		printf(COLOR_YELLOW " - ");
    	  	}
    	}

    	// Quand on arrive a la fin
    	// On va a la ligne
    	printf(COLOR_BLUE "|\n");
	}
	printf(COLOR_BLUE "+------------------------+\n\n");
}

/* On test si la case est libre */
int EstLibre (int ix, int iy){
  	// Declaration des variables
  	int i;

  	/*
  	Comment eviter que deux reines se menacent?!?

  	Deux reines sont dans la même ligne si i(x) = i(y).
	Elles sont sur la même diagonale si la droite qui les joint a pour coefficient
	directeur +1 ou -1 c.a.d : (i(x) - i(y)) / (i-y) = + ou - 1
    c.a.d, comme i > j, abs(dame(i) - dame(j)) = i - j
    */
  	for (i=0; i < iy; i++){
  		if ((array[i] == ix)||(abs(array[i]-ix) == abs(i-iy))){
  			return 0;
  		}
	}
	return 1;
}

/* On essaye de placer la Reine en N(x) de N(y) */
void PlaceReine(int n){
	// Déclaration des variables
	int i;

	// Si n == 8 on est arrivé au bout
	// donc on affiche l'echequier.
	if (n == limite) {
        cpt_sol++;
        printf(COLOR_CYAN"["COLOR_MAGENTA"Solution n°%d"COLOR_RESET""COLOR_CYAN"]\n", cpt_sol);
		AfficheEchequier();
	}
	// Sinon on vérifie que la case
	// est libre si c'est le cas on
	// essaye de placer une reine.
	else{
		for (i = 0; i < limite; i++){
			if (EstLibre(i,n)) {
				array[n] = i;
				PlaceReine(n+1);

			}
		}
	}
}

int main(){
	// Au lancement du programme
	// On instancie directement
	// notre fonction.
	PlaceReine(0);
	return 0;
}

