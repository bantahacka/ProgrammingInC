/************************************************************************
 *                                                                      *
 *   ints_opers1.c  Expressions - Qu. 2 Model Solution                  *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	/* declare local variables */
	int  a, b;         /* two values entered by user */

	/* prompt user for the 2 values */
	printf ("Enter the 2 values\n");
	scanf  ("%d %d", &a, &b);

	/* output various results */
	printf ("a - b = %d\n", a - b);
	printf ("a + b = %d\n", a + b);
	printf ("a * b = %d\n", a * b);
	printf ("a / b = %d\n", a / b);
	printf ("a %% b = %d\n", a % b);
	printf ("(a * a) + (b * b) = %d\n", (a * a) + (b * b));
	printf ("(a + b)   squared = %d\n", (a + b) * (a + b));

	return 0;

}







