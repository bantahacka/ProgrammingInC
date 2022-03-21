/* Pointers and Functions - Achieving a call by reference: Part 2  */
#include <stdio.h>

void swap(int *, int *);

int main(void)
{
	int x = 7,  y = 5;

	swap(&x, &y);
	printf("x is now %d and y is %d\n", x, y);

    return 0;
}

void swap (int *p1, int *p2)
{
	int temp;

	temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


