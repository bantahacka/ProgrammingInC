/*
 * The file mysort.c contains the sort() function
 */

/*
 * Include files:
 */
#include <stdio.h>
#include "defs.h"

/***********************************************************************
 * Function:  sort
 *
 * Input:     char word[]	- Character buffer entered by user
 * Output:    none
 *
 * Details:   Takes a string, and uses a 'classical' sort alg to sort
 *	      characters in ASCII order
 *
 ***********************************************************************/

void sort(char word[])
{ 
    char *s1, *s2;			    /* Working pointers 	*/
 
    char temp;				    /* 'Classical' swap var	*/
    int	mark;				    /* flag to indicate swap	*/
        					    /* is required		*/
 
    for( s1 = word ; *s1 ; s1++ )	/* s1 points to each char	*/
    {	        				    /* until the end of word	*/

	    temp = *s1 ;			    /* Usual initialisations	*/
	    mark = NO ;
 
	    for( s2 = s1 + 1; *s2 ; s2++ )
	    {				            /* Check s1 + 1 onwards    */
	        if ( *s2 < temp )		/* if char is smaller than */
	        {				        /* minimum, mark place     */
		    mark = s2 - s1;		    /* ready to swap	       */
		    temp = *s2;
	        }
	    }

	    if ( mark /* is set */ )
	    {				            /* Interchange *s1	   */
	        *s1 ^= *(s1 + mark);	/* and mark using	   */
	        *(s1 + mark) ^= *s1;	/* EXCLUSIVE OR	       */
	        *s1 ^= *(s1 + mark);	/* assignments	       */
	    }
    } /* For s1 = word   etc */
 
    return;
} 
