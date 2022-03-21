/************************************************************************
 *                                                                      *
 *    opers2.c Build and run this program for the answers to Qu.  2     *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main (void)
{
	int i, j, k;
	int max_val = 17;
	unsigned u;
	long bignumber;
	double db, result;

	u = 1;
	bignumber = 100000L;               /* long int constant */

	printf ("\nThe unsigned u is %u\n", u);

	printf("The result printed need not be saved:\n");
	printf("\tu - 10 is %u\t\t", u - 10);
	printf("\tu / 2  is %u\n", u / 2);

	printf("\nbignumber starts off as %ld\n", bignumber);
	printf("bignumber *= 100 is %ld\n", bignumber *= 100L);

	i = j = k = 0;

	i = -8 + max_val - 2;
	j = i++;
	k = 14 + 1 * 2;
	bignumber = 16L/6L;
	printf("\ni is %d\t\t\t", i);
	printf("j is %d\n", j);
	printf("k is %d\t\t\t", k);
	printf("bignumber is %ld\n", bignumber);

/*  And now a little bit on doubles */

	db = 35.05;

	result = db * (double) bignumber;
	printf("\ndb is %.2f, result is %.2f\n", db, result);

	return 0;
}
