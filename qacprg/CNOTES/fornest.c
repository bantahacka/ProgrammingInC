/* Looping Constructs - Nested Loops  */


/* Program to repeatedly calculate the sum from 1 to count      */
/* Program termintaes when 999 is entered                       */

#include <stdio.h>

int main(void)
{
	int count, number;
	long sum;
	printf("Please enter a number\n");
	scanf("%d", &number);

	while (number != 999)
	{
		for (sum = 0L, count = 1; count <= number; ++count)
			sum = sum + count;

		printf("The sum from 1 to %d is %ld\n\n", number, sum);
		printf("Please enter the next number\n");
		scanf("%d", &number);

	}

	return 0;
}

