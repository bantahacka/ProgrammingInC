/* Expressions, Assignments and Operators - Exercise  */
#include <stdio.h>

int main(void)
{
    int i = 10,j = 112, k;
    char letter = (char)j;

	k = !( i > 10) && ( j + i ) > 20;

    printf("%c\n", letter);
	printf("%d\n", k);
	printf("%d\n", !i);
	printf("%d\n", i++ > 10);

	return 0;
}

