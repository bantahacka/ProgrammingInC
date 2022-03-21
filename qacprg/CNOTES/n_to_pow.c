/* Functions and Program Structure - Passing Multiple Arguments  */
/* n raised to the power of p */

#include <stdio.h>

void n_to_power_p(int, int);            /* Prototype */

int main(void)
{
	int x = 2, y = 5;
	n_to_power_p(4, 3);     /* First Call  */
	n_to_power_p(x, y);     /* Second Call */
    
    return 0;
}

void n_to_power_p(int n, int p)
{
	int i, result;

	result = 1;
	for (i = 1; i <= p ; ++i)
		result = result * n;

	printf("%d to the power %d = %d\n", n, p, result);
}


