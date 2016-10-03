// Samuel Cardoso
// Exercice 1
// 26 septembre 2016
// Little programm who returns the length of a string
// without using strlen
#include <stdio.h>

/*
 * Function who returns the length of the given string
 * parameters : strInput
 * returns : Number of characters contained in the strInput
 */
unsigned int getStringLength(char strInput[])
{
    // We iterate in the array of characters until
    // we find the final character
    int i = 0;
    while(strInput[i] != '\0'){
        i++;
    }
    return i;
}

int main()
{
    // set the string and show how many characters she have
    char strWord[] = "test";
    printf("Le nombre de charactère contenu dans \"test\" est : %d\n", getStringLength(strWord));
    return 0;
}