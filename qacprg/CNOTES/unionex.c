/* Structures and Unions - Accessing Unuin Members */

#include <stdio.h>

union Values
{
	int n;
	char c;
	double r;
};

int main(void)
{
	union Values current_vals ;

	current_vals.n = -77 ;
	printf("integer value = %d\n",current_vals.n);

	current_vals.c =  'H';
	printf("character value = %c\n",current_vals.c);

	current_vals.r = 908.87 ;
	printf("double value = %f\n",current_vals.r);

    return 0;
}
