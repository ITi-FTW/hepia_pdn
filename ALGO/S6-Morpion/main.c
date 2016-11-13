#include <stdio.h>
/*********************************************************************
 Auteur : José Gonçalves
 Date : 10.11.16
 Description : Jeu du Morpion
**********************************************************************/
/*
 * Initialisation des variables et énumérateurs
 */

// Couleurs pour le terminal
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define NBLINE 3
#define NBCOL 3
typedef enum {EMPTY, CIRCLE, CROSS} Tokens;            // Type de "jetons"
typedef enum {FALSE, TRUE} Boolean;                    // Création d'un énumérateur
static Tokens tab[NBLINE][NBCOL];                   // grille du morpion valeurs possibles EMPTY, CIRCLE ou CROSS
static int PlayerToken = CIRCLE;                       // Type de jeton utilisé par le Joueur 2

/*
 * Initiliase la grille du morpion a vide
 */
void initTab() {
    // Init vars :
    int i, j;

    for (i=0; i < NBLINE ; i++) {
        for (j=0; j < NBCOL ; j++) {
            tab[i][j] = EMPTY;                            // Pour commencer on passe tout à vide
        }
    }
}

/*
 * Procédure qui affiche soit :
 *  - dans le cas EMPTY
 *  O si c'est un CIRCLE
 *  X si c'est une CROSS
 */
void afficheTab() {
    int i, j;

    printf(ANSI_COLOR_GREEN"[Morpion v. 1.0 ] -------------"ANSI_COLOR_RESET"\n");
    for (i=0; i < NBLINE; i++) {
        for (j=0; j < NBCOL; j++) {
            switch (tab[i][j]) {
                case EMPTY:
	                printf(ANSI_COLOR_BLUE" _ "ANSI_COLOR_RESET);
	                break;
                case CIRCLE:
	                printf(ANSI_COLOR_MAGENTA" O "ANSI_COLOR_RESET);
	                break;
                case CROSS:
	                printf(ANSI_COLOR_RED" X "ANSI_COLOR_RESET);
	                break;
            }
        }
        printf("\n");                                           // Saut de ligne
    }
}

/*
 * Poser un nouveau jeton.
 * Pose un nouveau jeton sur le tableau que l'utilisateur a saisie.
 * Si la case se trouve en dehors du tableau une erreur est levée.
 */
void poseToken() {
    // Init vars.
    int line, col;

    // Protection de la saisie
    Boolean inputCorrect = FALSE;

    do {
        // Demande les coordonnées aux joueurs:
        printf(ANSI_COLOR_GREEN"[ Actions du joueur ] ---------"ANSI_COLOR_RESET"\n");
        printf(ANSI_COLOR_YELLOW"[Joueur]"ANSI_COLOR_RESET" "ANSI_COLOR_CYAN"=> Numero de ligne :"ANSI_COLOR_RESET);
        scanf("%d", &line);
        printf(ANSI_COLOR_YELLOW"[Joueur]"ANSI_COLOR_RESET" "ANSI_COLOR_CYAN"=> Numero de colonne :"ANSI_COLOR_RESET);
        scanf("%d", &col);

        /*
         * Si la line est > que 0 et que line < ou égale a NBLINE
         * et que la colone est > 0 et que col est NBCOL alors
         * cela permet d'eviter de se casser la tete avec des tableau
         * qui commence a 0
         */
        if ((line > 0) && (line <= NBLINE) && (col > 0) && (col <= NBCOL)) {
            line--;
            col--;
            if (tab[line][col] != EMPTY) {
                // Si la case n'est pas vide alors on le notifie
                printf(ANSI_COLOR_RED"[Information] "ANSI_COLOR_CYAN"=> Cette case est déjà prise. Inséré une nouvelle coordonée :"ANSI_COLOR_RESET"\n");
            }
            else {
	            inputCorrect = TRUE;
                tab[line][col] = (Tokens) PlayerToken;
	            if (PlayerToken == CIRCLE)
                    PlayerToken = CROSS;
	            else
                    PlayerToken = CIRCLE;
                }
        }
        else
            printf(ANSI_COLOR_RED"[Information] "ANSI_COLOR_CYAN"=> Les coordonées fournies sont incorrectes. Inséré une nouvelle coordonée :"ANSI_COLOR_RESET"\n");
    } while (!inputCorrect);
}

/*
 * Teste si l'un des joueurs à gagne (ligne, colonne ou diagonale remplit
 * de jetons semblables).
 */
Boolean testeFinJeu() {
    // Init Vars :
    int i,j;
    int Winner = 0;                         // Si CROSS = Joueur 1 si CIRLE = joueur 2
    Boolean Finish = FALSE;

    /*
    * Teste s'il y a un gagnant :
    * Ne supporte que 3x3 je devrais pouvoir l'amélioré avec
    * une boucle for plutot que de fournir les coordonnées manuellement.
    */
    if (tab[1][1] != EMPTY) {
        if (((tab[0][1] == tab[1][1]) && (tab[1][1] == tab[2][1])) ||               /* colonne 1 */
	        ((tab[1][0] == tab[1][1]) && (tab[1][1] == tab[1][2])) ||               /* ligne 1 */
	        ((tab[0][0] == tab[1][1]) && (tab[1][1] == tab[2][2])) ||               /* diagonale */
	        ((tab[0][2] == tab[1][1]) && (tab[1][1] == tab[2][0]))){                /* autre diag */
            Winner = tab[1][1];                                                              /* ie ROND ou CROIX */
            Finish = TRUE;
        }
    }

    /*
     * Si la case 0,0 est vide, cela signifie que
     * la ligne 0 et le colonne 0 ne sont pas gagnantes
     */
    if ((!Finish) && (tab[0][0] != EMPTY)) {
        if (((tab[0][0] == tab[0][1]) && (tab[0][1] == tab[0][2])) ||               /* ligne 0 */
            ((tab[0][0] == tab[1][0]) && (tab[1][0] == tab[2][0]))) {               /* colonne 0*/
            Winner = tab[0][0];
            Finish = TRUE;
        }
    }

    /*
     * Si la case 2,2 est vide, cela signifie que
     * la ligne 2 et la colonne 2 ne sont gagnantes
     */
    if ((!Finish) && (tab[2][2] != EMPTY)) {
        if (((tab[2][0] == tab[2][1]) && (tab[2][1] == tab[2][2])) ||               /* ligne 2 */
	        ((tab[0][2] == tab[1][2]) && (tab[1][2] == tab[2][2]))) {               /* colonne 2 */
            Winner = tab[2][2];
            Finish = TRUE;
        }
    }

    /*
     * Messge de Fin
     * Si c'est fini alors on Velicite le joueur 1 ou joueur 2
     */
    if (Finish) {
        printf(ANSI_COLOR_RED"[Information] "ANSI_COLOR_CYAN"=> Felicitations au joueur ayant les ");
        if (Winner == CIRCLE)
            printf(ANSI_COLOR_YELLOW"Ronds,"ANSI_COLOR_RESET" "ANSI_COLOR_CYAN"qui a gagné!"ANSI_COLOR_RESET"\n");
        else
            printf(ANSI_COLOR_YELLOW"Croix,"ANSI_COLOR_RESET" "ANSI_COLOR_CYAN"qui a gagné!"ANSI_COLOR_RESET"\n");

        // On retourne vrai pour finir le jeu
        return TRUE;
    }

    /*
     * On Teste si la grille n'est pas pleine
     */
    for (i=0; i < NBLINE; i++) {
        for (j=0; j < NBCOL; j++) {
            // Si on à au moins 1 case vide alors
            // on continue a joué
            if (tab[i][j] == EMPTY)
	            return FALSE;
        }
    }
    return TRUE;
  
}

/*
 * Debut du programme!
 */
int main() {
    // On initie notre tableau vide
    initTab();

    // Tant que qu'il n'y a pas de gagnant
    // Ou que le tableau n'est pas plein alors
    // on pose un jeton et on affiche le tableau.
    do {
        poseToken();
        afficheTab();
    } while(!testeFinJeu());
    return 0;
}