/* Pointers and Arrays - Pointers, Arrays and Functions */

#include <stdio.h>

int array_sum(int *, int );

int main(void)
{
	int a [5] = {46, 19, 77, 4, 1};
	printf ("The sum of the array is %d\n", array_sum ( a, 5 ));

    return 0;
}
/* Function to sum the elements of an integer array	*/

int array_sum (int *pa, int n)
{
	int sum  = 0 ;
	int  *array_end = pa + n ;

	while ( pa < array_end )
		sum += *pa++;

	return sum ;
}
