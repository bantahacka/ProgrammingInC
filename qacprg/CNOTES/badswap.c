/* Functions and Program Structure  -  Does this swap() function work?  */

#include <stdio.h>
void swap(int, int);

int main(void)
{
	int x = 7,  y = 5;

	swap(x, y);
	printf("x is now %d and y is %d\n", x, y);

    return 0;
}

void swap (int num1, int num2)
{
	int temp_num;

	temp_num = num1;
	num1 = num2;
	num2 = temp_num;
	printf("num1 is now = %d\n", num1);
}


