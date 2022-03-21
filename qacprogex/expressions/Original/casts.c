/************************************************************************
 *                                                                      *
 *   casts.c  Expressions - Qu. 4 Code Template                         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	/* declare local variables */
	int   age1;      /* age 1 entered by user */
	int   age2;      /* age 2 entered by user */
	int   age3;      /* age 3 entered by user */
	int   age4;      /* age 4 entered by user */
	double average;  /* average age */
	int average_as_int;

	/* prompt user for 4 ages, and read 'em in */
	printf ("Enter 4 student ages\n");
	scanf  ("%d %d %d %d", &age1, &age2, &age3, &age4);

	/* calculate average age exactly - no loss of accuracry here! */

	/* print average age */

	/* calculate and print average as an int using explicit int cast */

	/*  what about implicit conversion? */


	return 0;

}
