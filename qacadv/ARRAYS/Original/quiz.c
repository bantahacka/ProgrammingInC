/*********************************************************************
 *                                                                   
 *  Filename:     QUIZ.C
 *  Directory:    ARRAYS
 *
 *  Description:  This program displays the answer to the pencil-and-paper
 *                quiz on pointers and arrays.
 *
 *********************************************************************/

#include <stdio.h>

char*	c[] = 
{
	"Two",
	"Enter",
	"Hell",
	"Harold"
};

char**	cp[] =
{ 
	c + 3,
	c,  
	c + 2,
	c + 1
};     

char***	cpp = cp;

int main(void)
{
    printf("%s",   *cpp[2]);
    printf("%s ",  **++cpp + 2);
    printf("%s",   **cpp + 1);
    printf("%s",   *cpp[2] + 4);
    printf("%s\n", cpp[1][1] + 4);

    return 0;
}
