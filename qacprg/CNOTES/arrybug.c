/* 	arrybug.c - spot the bug	*/

#include <stdio.h>

void initialise_array (int*,  int) ;

int main(void)
{
	int x[10]  = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3 } ;
	int y[7] = { 2, 2, 2, 2, 2, 2, 2 } ;
	initialise_array (x, 10) ;
	initialise_array (y, 7) ;

	return 0;
}

void initialise_array(int *pa, int n)
{
	int *array_end = pa + n;
/*	                 ^^^^^^  NEEDS INITIALISING */

	while (pa < array_end)
		*pa++ = 0 ;

}
