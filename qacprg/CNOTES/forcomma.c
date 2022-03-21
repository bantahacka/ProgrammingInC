/* Looping Constructs -  More on the for loop     */

/* for statement showing the comma operator */

#include <stdio.h>

int main(void)
{
	int count, sum;
        
    for(sum = 0, count = 1; count <= 7; count++)
	{
		sum = sum + count;
		printf("%d %d\n", count, sum);
	}

	return 0;
}

