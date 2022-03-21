/***********************************************************************
 * Function:  search
 *
 * Input:     char ch	    - Character to search for
 *	      char word[]   - Character buffer entered by user
 * Output:    none
 *
 * Details:   Takes a character and a string as parameters,
 *	      and performs a 'binary chop' method of search
 *
 ***********************************************************************/

/*
 * Include files:
 */
#include <stdio.h>
#include "defs.h"

int search(char ch, char word[])
{ 
    char *start;			/* Working pointers	   */
    char *end;
    char *mid;
    char *where;

    start = word;		       /* Start at first char	   */
    end   = word;		       /* safety procedure	   */
    where = word;
        
    while ( *end )		       /* Wind end to last char    */
    {
    	end ++;
    }

    while ( start <= end )
    {
	    /* Find the 'middle' pos	*/
	    mid = start + ( end - start ) / 2 ;
         
	    if ( *mid == ch )	     /* Found it there ??	    */
	    {
	        where = mid;
	        while (*where == ch)
	        {
	    	    where-- ;
	        }
	        return ( where - word + 2 );
	    }

	    if ( *mid < ch )	      /* Look at end half	    */
	    {
	        start = mid + 1;
	    }
	    else    			      /* or the first half	    */
	    {
	        end = mid - 1 ;
	    }
    }
      
    /* If we get this far then no match found */
    /* NB see return statement earlier in function */
    return 0 ;
} 
