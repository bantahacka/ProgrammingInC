/* Arrays - Operations on Arrays */

#include <stdio.h>

int a[10] = {2,3,4,5,6,7,8,9,10,11};

int main(void)
{
	int b[10];
	int i;

	for (i = 0; i < 10 ; i++)
		b[i] = 0;

	for (i = 0; i < 10 ; i++)
		b[i] = a[i];

	for (i = 0; i < 10 ; i++)
		printf("%d ", a[i]);

	printf ("Please input 10 integers \n");
	for (i = 0; i < 10 ; i++)
		scanf("%d ", &a[i]);

    return 0;
}


