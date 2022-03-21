/*
 *  The program all.c contains the entire code for
 *  the suite main,gets,search and mysort used to
 *  demonstrate multi-source file programming
 */

#define 	NO	0
#define     STRLEN  80 
#define     NEWLINE '\n' 
#define     SPACE   ' ' 
#define     TAB     '\t' 
#define     NULL    '\0' 

/*
 * Include files:
 */
#include <stdio.h>
 
/*
 * Function prototypes:
 */
int main      (void);              /* Main function                */
void getstring (char *buff);	   /* Get string from user	   */
void sort      (char word[]);	   /* Sort string alphabetically   */
int  search    (char ch,	   /* Search for particular char   */
                char word[]);
int  display   (int position,
                char c,
                char word[]);      /* Display the result of search */


/*******************************************************************
 * Function:  main
 *
 * Input:     none
 * Output:    none
 *
 * Details:   main function is entry point to C program!
 *  	      Calls getstring() to get string from user
 *	          Calls sort()	to sort string alphabetically
 *	          Calls search()	to search for a particular char
 *            Calls display()   to display the result 
 *
 *******************************************************************/
int main(void)
{ 
    char string[STRLEN + 1];	/* Buffer for user input	*/
         
    int pos;			        /* Used for character position	*/
    int c;			            /* and User character input	*/
    int found = 1 ;             /* boolean for display's return */

    printf("Please type in a string to be sorted and searched\n");
         
    getstring(string);		    /* Call to 'procedure' getstring */
				                /* and	takes a string from user */
 
    printf("You typed in: \t\t");
    printf("%s\n", string);	    /*	prints it    */
 
    sort(string);		        /*	and sorts it */
 
    printf("Please type in a character to search for  ");
 
    c = getchar();		        /* Take in a character from user */
				                /* and search for it in string	 */

    pos = search((char)c, string);
 
    found = display(pos, (char)c, string);

    return 0;
}

/***********************************************************************
 * Function:  getstring
 *
 * Input:     char * buff    - Input buffer for string
 * Output:    none
 *
 * Details:   Takes a string, char by char from user and places it
 *	            into a buffer provided by the formal parameter
 *
 ***********************************************************************/
void getstring(char *buff)
{
    int ch;             /* User input    */
    int i = 0;          /* buffer offset */
 
    while( (ch = getchar()) != NEWLINE && i < STRLEN )
    {
	    if ( ch != SPACE && ch != TAB )
	    {
	        *( buff + i) = (char)ch ;	   /* This one is OK	*/
	        i ++ ;
	    }
    }
    *( buff + i ) = '\0';		   /* User Termination	*/
 
    return;
}

/***********************************************************************
 * Function:  sort
 *
 * Input:     char word[]	- Character buffer entered by user
 * Output:    none
 *
 * Details:   Takes a string, and uses a 'classical' sort alg to sort
 *	          characters in ASCII order
 *
 ***********************************************************************/
void sort(char word[])
{ 
    char *s1, *s2;			    /* Working pointers 	*/
 
    char temp;				    /* 'Classical' swap var	*/
    int	mark;				    /* flag to indicate swap	*/
				        	    /* is required		*/
 
    for( s1 = word ; *s1 ; s1++ )   /* s1 points to each char	*/
    {					            /* until the end of word	*/

	    temp = *s1 ;			    /* Usual initialisations	*/
	    mark = NO ;
 
	    for( s2 = s1 + 1; *s2 ; s2++ )
	    {				            /* Check s1 + 1 onwards    */
	        if ( *s2 < temp )		/* if char is smaller than */
	        {				        /* minimum, mark place     */
		        mark = s2 - s1;		/* ready to swap	       */
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
 
    printf("The sorted string is:\t");
    printf("%s\n",word);
      
    return;
} 

/***********************************************************************
 * Function:  search
 *
 * Input:     char ch	    - Character to search for
 *	          char word[]   - Character buffer entered by user
 * Output:    none
 *
 * Details:   Takes a character and a string as parameters,
 *	          and performs a 'binary chop' method of search
 *
 ***********************************************************************/

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
	    else			          /* or the first half	    */
	    {
	        end = mid - 1 ;
	    }
    }
      
    /* If we get this far then no match found */
    /* NB see return statement earlier in function */
    return 0 ;
} 

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
