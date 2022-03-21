/* Looping Constructs - A while Loop with a Compound Body */

#include <stdio.h>

int main(void)
{
	int num1 = -1,
	    num2 = -1;

    while (num1 <= 0 || num2 <=0)
	    printf("Enter two positive integers\t") ;
	    scanf("%d %d", &num1, &num2) ;

	printf("This statement will not get reached!\n");

	return 0;
}
