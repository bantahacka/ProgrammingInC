/************************************************************************
 *                                                                      *
 *   format2.c  Data Types - Qu. 4 Model Solution (using doubles)       *
 *                                                                      *
 ************************************************************************/



#include <stdio.h>

int main(void)
{
	double number1;
	double number2;

	printf("\nThink of a number - any number!");
	scanf("%lf", &number1);
	printf("\nNow choose another number.");
	scanf("%lf",&number2);

	printf("You have chosen number1 = %f and number2 = %f\n", number1, number2);

	return 0;

}
