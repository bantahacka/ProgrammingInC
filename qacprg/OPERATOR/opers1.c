/************************************************************************
 *                                                                      *
 *    opers1.c Build and run this program for the answers to Qu.   1    *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main (void)
{
	int i = 7, j;

/*  increment operators */

	printf ("i started off as %d\t", i);
	printf ("++i is %d\t", ++i);
	printf ("and (think about this!) i++ is %d\n\n", i++);

/* assignment operators/updaters */

	j = i;
	printf ("Assignment operators ... so\t\t");
	printf ("\ti = i * 10 is %d\n", i = i * 10);
	printf ("but can also be written as:\t\t");
	printf ("\ti *= 10  which is now %d\n", i *= 10);

	i = j;
	printf ("\nalso available are -, / and %% ... so\t");
	printf ("\ti = i %% 7 is %d\n", i = i % 7);
	i = j;
	printf ("but can also be written as:\t\t");
	printf ("\ti %%= 10  which is %d\n", i %= 10);

    return 0;
}
