/* Expressions, Assignments and Operators */
/* Side effects of the Increment Decrement Operators  */

/* Prefix increment  */

#include <stdio.h>

int main(void)
{
	int i, result;

	i = 7;
	result = ++i;
	printf("%d %d", i, result);

	return 0;
}

