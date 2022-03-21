/*      Program to perform arithmetic on 2 numbers */

#include <stdio.h>

int main(void)
{
	int x, y, sum;

	printf("Please Input two numbers: \n");
	scanf("%d %d", &x, &y);

	sum = x + y;

	printf("The sum of %d and %d is %d\n", x, y, sum);

	return 0;
}


