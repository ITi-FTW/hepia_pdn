/**
 * @file       main.c
 * @author     Nicolas Hedger
 * @date       2016.10.06
 * @brief      Programme qui affiche "Hello World !"
 * 
 * L'étude du code source de ce programme permet de comprendre
 * de quelle manière procéder pour afficher un message dans la
 * console.
 */

#include <stdio.h>

/**
 * @brief      Fonction principale
 * @return     Un entier valant 0
 */
int main(void)
{
    /**
     * Affiche le message "Hello World !" suivi d'un saut
     * de ligne à l'aide de la fonction printf.
     * 
     * @see        https://fr.wikipedia.org/wiki/Printf#C
     */
	printf("Hello World !\n");
    
	return 0;                  
}