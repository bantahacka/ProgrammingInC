/* Pointers - Declaring Pointers, a closer look   */

#include <stdio.h>

int main(void)
{
	int x = 10;
	int y;
	int *px = &x;

	x = *px + 1;
	y = *px / 2 + 10 -7;
	if (*px > 10)
		printf("*px is %d\n", *px);

    return 0;
}

