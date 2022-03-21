/* Pointers - Mixing Unary and Binary "*"  */

#include <stdio.h>

int main(void)
{
	int i = 3, j = 2, k;
	int *p = &i;
	int *q = &j;


	k = *p * *q;      printf("k is %d\n", k);

	k = (*p)++ * *q;  printf("k is %d\n", k);

	k = *p/*q;      printf("k is %d\n", k);

    return 0;
}

