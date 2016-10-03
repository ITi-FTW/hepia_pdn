#include <stdio.h>
// -------------------------------------------------------------------------------
// Auteur : José Gonçalves
// Date : 23.09.16
// Description : Ecrire un algorithme qui décompose une somme d’argent inférieure
// à 1000 FrS (sans centimes) en billets de 100, 50, 20, 10 et pièces de 5, 2 et
// 1 (voir diapo 22 du document « 1 »).
// -------------------------------------------------------------------------------

int main(){
	
	// Declaration et initialisation des variables
	int somme = 0;
	int cpt_100 = 0;
	int cpt_50 = 0;
	int cpt_20 = 0;
	int cpt_10 = 0;
	int cpt_5 = 0;
	int cpt_2 = 0;
	int cpt_1 = 0;
	
	// Apparement en C les booleens n'existe pas alors je les cree
	typedef enum { false, true } bool;
	bool val_limite = false;

	// Declaration et initialisation des constantes
	const int valeur1 = 100;
	const int valeur2 = 50;
	const int valeur3 = 20;
	const int valeur4 = 5;
	const int valeur5 = 2;
	const int valeur6 = 1;

	// En-tete
	printf("------------------------------------\n");
	printf("- Calcul de retour de monnaie      -\n");
	printf("------------------------------------\n");

	// Boucle de test si la valeur est inferieur a 1000
	while (val_limite == false){
		printf("\nVeuillez donner votre valeur :");
		scanf("%d", &somme);

		if (somme > 1000){
			printf("Desole votre valeur depasse la valeur limite. (max:1000)");
			val_limite = false;
		}else{
			val_limite = true;
		}
	}
	
	// Boucle de calcul de retour de monnaie
	while (somme > 0){
		if (somme >= valeur1){
			somme = somme - valeur1;
			cpt_100 = cpt_100+1;
		}
		else if (somme >= valeur2){
			somme = somme - valeur2;
			cpt_50 = cpt_50+1;
		}
		else if (somme >= valeur3){
			somme = somme - valeur3;
			cpt_20 = cpt_20+1;
		}
		else if (somme >= valeur4){
			somme = somme - valeur4;
			cpt_5 = cpt_5+1;
		}
		else if (somme >= valeur5){
			somme = somme - valeur5;
			cpt_2 = cpt_2+1;
		}
		else{
			somme = somme - valeur6;
			cpt_1 = cpt_1+1;
		}
	}

	// Bas de page
	printf("\n------------------------------------\n");
	printf("------------------------------------\n");
	
	// Resultat
	printf("- Voici votre retour monnaie : \n");
	printf("\n-> Billet(s) de %d : %d",valeur1,cpt_100);
	printf("\n-> Billet(s) de %d : %d",valeur2,cpt_50);
	printf("\n-> Billet(s) de %d : %d",valeur3,cpt_20);
	printf("\n-> Piece(s) de %d : %d",valeur4,cpt_5);
	printf("\n-> Piece(s) de %d : %d",valeur5,cpt_2);
	printf("\n-> Piece(s) de %d : %d", valeur6,cpt_1);
	printf("\n----> Aurevoir!                        \n");
	printf("------------------------------------\n");

	// Retour de fonction
	return 0;

}