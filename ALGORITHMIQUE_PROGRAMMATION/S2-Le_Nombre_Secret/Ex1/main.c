#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

// Attention dans ce programme si on veut utiliser getpid() on doit faire appel aux
// Librairies Unix "unistd.h" car c'est à la base une commande UNIX
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
    
    // Debut du jeu
	printf("J'ai choisi un nombre entre 1 et %d.\n", num_max);
	printf("A vous de deviner en %d essai.\n", nb_essai);
    
    // Boucle de jeu tant que le numéro donnée n'est pas le bon
    // alors on continue a boucler.
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
    
    // Si le nombre d'essai est dépassé alors le joueur à perdu.
	if (nb_essai > nb_essai_max){
		printf("Désolé, vous avez utilisé vos %d essais... Dommage... t'es mauvais.", nb_essai_max);
		printf("J'avais choisi comme nombre aleatoire : %d", nombre_aleatoire);
	}
    
    // retour de fonction (code 0)
	return 0;
}
