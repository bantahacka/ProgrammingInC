/* Expressions, Assignments  and Operations      */
/* Increment and Decrement Operator Expressions  */

#include <stdio.h>

int main(void)
{
	int a,b,c;

	a = b = 0;
	c = 1;

	a = ++b + ++c;
	printf("%d %d %d\n", a, b, c);

	a = b++ + c++;
	printf("%d %d %d\n", a, b, c);

	a = ++b + c++;
	printf("%d %d %d\n", a, b, c);

	a = b-- + --c;
	printf("%d %d %d\n", a, b, c);

	return 0;
}




