/***********************************************************************
 * Function:  getstring
 *
 * Input:     char * buff    - Input buffer for string
 * Output:    none
 *
 * Details:   Takes a string, char by char from user and places it
 *  	      into a buffer provided by the formal parameter
 *
 ***********************************************************************/

/*
 * Include files:
 */
#include <stdio.h>
#include "defs.h"

void getstring(char *buff)
{
    int ch;             /* User input    */
    int i = 0;          /* buffer offset */
 
    while( (ch = getchar()) != NEWLINE && i < STRLEN )
    {
	    if ( ch != SPACE && ch != TAB )
	    {
	        *( buff + i) = (char)ch ;	/* This one is OK	*/
	        i ++ ;
	    }
    }
    *( buff + i ) = '\0';		        /* User Termination	*/
 
    return;
}
