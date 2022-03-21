/* Pointers and Arrays - Dynamic Memory Allocation */

#include <stdlib.h>
#include <stdio.h>

int main (void)
{
	int *dynamica;       /* Used to hold the base address   */
	int size;            /* of a dynamic array of size ints */
	int i;

	printf("Please type in the size of your dynamic array \t");
	scanf("%d", &size);
	if(size <= 0 || size > 1000)
		 exit(1);

    dynamica = malloc(size * sizeof(int));   /* enough for an array of ints */
    dynamica[0] = 42;                        /* assign to element 0             */

	for(i = 0; i < size; i++)
		printf("%d ", dynamica[i]);

	free(dynamica);

    return 0;
}
