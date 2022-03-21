/************************************************************************
 *                                                                      *
 *   oper_precidence.c  Expressions - Qu. 1 Code Template               *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	/* declare local variables */
	int a, b, c, d;

	a =  -3 + 4 * 5 - 6;
	b =   3 + 4 % 5 - 6;
	c =  -3 * 4 % -6 / 5;
	d =  (7 + 6) % 5 / 2;

	printf ("%d %d %d %d\n", a, b, c, d);

	return 0;
}
