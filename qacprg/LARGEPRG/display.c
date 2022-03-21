/*******************************************************************
 * Function:  display
 *
 * Input:     int position      position of char in string
 *            char c            char possibly found in string
 *            char word[]       string to be searched
 * Output:    int               curtesy boolean
 *
 * Details:   takes a number and prints a '^' at that position in
 *            the string
 *
 *******************************************************************/

/*
 * Include files:
 */

#include <stdio.h>
#include "defs.h"

int display(int position, char c, char word[])
{
    int found = 1;
    int i;
    if (position)
    {
	    printf("\nCharacter %c found in position %d\n\n", c,position);
	    printf("%s\n", word);
	    for (i = 0 ; i < position - 1 ; i++) printf(" ");
    	    printf("^\n");
	    printf("i.e. here!\n");

    }
    else
    {
	    printf("\nCharacter %c not found\n\n", c);
	    found = 0;
    }
    return found;               /* To be polite! */
}
