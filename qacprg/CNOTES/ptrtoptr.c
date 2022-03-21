/* Pointers - Pointers to Pointers   */
#include <stdio.h>

int main(void)
{
	int i = 3, j = 2, k;
	int *p = &i;
	int *q = &j;
	int **pp;

	pp = &p;
	printf("**pp is %d\n", **pp);

	p = q;
	printf("**pp is %d\n", **pp);

	k = *p***pp;
	printf("k is %d\n", k);

	return 0;
}

