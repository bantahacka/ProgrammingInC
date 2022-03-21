/*******************************************************************
 * Function:  main
 *
 * Input:     none
 * Output:    none
 *
 * Details:   main function is entry point to C program!
 *            Calls getstring() to get string from user
 *            Calls sort()      to sort string alphabetically
 *            Calls search()    to search for a particular char
 *            Calls display()   to display the result
 *
 *******************************************************************/

/*
 * Include files:
 */

#include <stdio.h>
#include <stdlib.h>
#include "defs.h"

/*
 * Global variable:
 */

char string[STRLEN + 1] ;

int main(void)
{ 
    int pos;                    /* Used for character position  */
    int c;                      /* and User character input     */
    int found = 1 ;             /* boolean for printres return  */

    printf("Please type in a string to be sorted and searched\n");
     
    getstring(string);          /* Call to 'procedure' getstring */
                				/* and	takes a string from user */
 
    printf("\nYou typed in: \t\t");
    printf("%s\n", string);     /*      prints it    */
 
    sort(string);               /*      and sorts it */

    printf("The sorted string is:\t %s\n", string);
 
    printf("\nPlease type in a character to search for  ");
 
    c = getchar();              /* Take in a character from user */
				                /* and	takes a string from user */

    pos = search((char)c, string);
 
    found = display(pos, (char)c, string);

    return 0;
}
