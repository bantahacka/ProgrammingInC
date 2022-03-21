/*      Program to perform arithmetic on 2 numbers */

#include <stdio.h>

int main(void)
{
	int x, y, sum, difference, product, quotient;


	printf("Please Input two numbers: \n");
	scanf("%d %d", &x, &y);

	sum = x + y;

	printf("The sum of %d and %d is %d\n", x, y, sum);

	difference = x - y;

	printf("The difference of %d and %d is %d\n", x, y, difference);

	product = x * y;

	printf("The product of %d and %d is %d\n", x, y, product);

	quotient = x / y;

	printf("The quotient of %d and %d is %d\n", x, y, quotient);

	return 0;
}


