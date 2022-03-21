/* Pointers and Arrays - Using * with ++ */

#include <stdio.h>

int a[5] = {46, 19, 77, 4, 1};

int main(void)
{
	int *p = a;
	int *end = a + 5;
	int sum = 0;

	while(p < end)
		sum += *p++;
	printf("Total is %d\n", sum);

	return 0;
}
