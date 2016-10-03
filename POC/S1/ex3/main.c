// Samuel Cardoso
// Exercice 3
// 26 septembre 2016
// Little programm who fill the spaces of a string with a character
// given in parameter
// without using strlen
#include <stdio.h>
#include <string.h>

// Define our struct who contains
// the parameters to the fillWhiteSpaces method
typedef struct Parameter
{
    char cRplCharacter;
    char strInput[];
} rplStr_t;

/*
 * Function who fills the spaces with the choosen character
 * parameters :
 * - *parameters, pointer to a Parameter struct
 * returns : none
 */
void fillWhiteSpaces(struct Parameter *parameters)
{
    // Show the value before the transformation
    printf("-- BEFORE --\n");
    printf("%s\n", parameters->strInput);

    // We iterate in the array of characters until
    // we find the final character and fill the white
    // space with the choosen characters
    int i = 0;
    while(parameters->strInput[i] != '\0')
    {
        if (parameters->strInput[i] == ' ')
        {
            parameters->strInput[i] = parameters->cRplCharacter;
        }
        i++;
    }

    // Show the transformation
    printf("-- AFTER --\n");
    printf("%s\n", parameters->strInput);
}

int main()
{
    // Create our string and initialize our struct
    char strWord[] = {'t','e',' ','s','t'};
    struct Parameter parameters;
    parameters.cRplCharacter = 'c';
    strncpy(parameters.strInput, strWord, 5);

    // Call our function with the value of our struct
    fillWhiteSpaces(&parameters);

    // EXIT
    return 0;
}