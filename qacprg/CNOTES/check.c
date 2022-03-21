#define	DEBUG	  1

#include <stdio.h>
#include  "debug.h"

void func(int);

int main(void)
{
	int positive;
	printf("Please type in a positive number\t");
	scanf("%d", &positive);
	func(positive);

	return 0;
}

void func(int a)
{
	CHECK (a > 0);
	
	printf("\nEnd of Demonstration\n");
}
