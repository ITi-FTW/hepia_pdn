#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// ATTENTION COMPILATION - CREATION DES LIENS VERS LIB MATH 
// commande : gcc main.c -lm -o main
// ---------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Devine quel est le nombre caché.
// ---------------------------------------------------------------------------------



int main(){
	// Declaration et init. des variables
	int nb_essai_max = 10;
	int nb_essai = 1;
	int mon_num = 10;
	int num_max = 300;

	// Definition du "seed" 
	srand(getpid());

	// On se trouve un chiffre aleatoire
	int nombre_aleatoire = rand() % num_max;

	printf("J'ai choisi un nombre entre 1 et %d.\n", num_max);
	printf("A vous de deviner en %d essai.\n", nb_essai);

	while (mon_num != nombre_aleatoire && nb_essai <=nb_essai_max) {
		printf("Essai n°%d : \n", nb_essai);
		printf("Donnez une valeur : \n"); 
		scanf("%d", &mon_num);
		if (nombre_aleatoire < mon_num) {
			printf("Trop petit!\n");
		}
		else if (nombre_aleatoire > mon_num){
			printf("Trop grand!\n");
		}
		else{
			printf("Bravo! T'as trouvé le bon numéro (%d) en %d coups!", nombre_aleatoire, nb_essai);
		}
	}

	if (nb_essai > nb_essai_max){
		printf("Désolé, vous avez utilisé vos %d essais... Dommage... t'es mauvais.", nb_essai_max);
		printf("J'avais choisi comme nombre aleatoire : %d", nombre_aleatoire);
	}

	return 0;
}