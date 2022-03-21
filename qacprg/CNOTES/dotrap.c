/* Looping Constructs - do/while Exercise   */
/* The left-hand one */

#include <stdio.h>

int main(void)
{
	int x;
	do
	{
		printf("Please enter a non-zero integer\n");
		scanf("%d", &x);
	}
	while (x=0);

	return 0;
}


