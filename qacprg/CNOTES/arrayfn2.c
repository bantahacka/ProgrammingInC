/* Arrays - Arrays with Functions an example         */

#include <stdio.h>

void initialise_array(int [], int);     /* Prototype */

void print_array(int [], int);

int main(void)
{
	int x[100];
	int y[7] = { 1,2,3,4,5,6,7};

	initialise_array(x,100);
	initialise_array(y,7);

	print_array(x, 100);
	print_array(y,7);

    return 0;
}

/* Initialise array with zeros */

void initialise_array(int ai[], int size)
{
	int i;

	for (i = 0; i < size ; i++)
		ai[i] = 0;
}


void print_array(int ai[], int size)
{
	int i;

	for (i = 0; i < size ; i++)
		printf("%d ", ai[i]);

	printf("\n\n");
}


