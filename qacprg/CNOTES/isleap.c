/* Functions and Program Structure - How can Return Values be Used?  */

#include <stdio.h>

int is_leap(int year);            /* Prototype */


int main(void)
{
	int x, y = 1995;

	x = is_leap(y);

	if(is_leap(1984))
		printf("Leap\n");

	printf("%d\n", is_leap(y+1));

    return 0;
}

int is_leap(int year)
{
    if (year % 4 == 0 && year % 100 != 0)
		return 1;
	else
		return 0;
}


