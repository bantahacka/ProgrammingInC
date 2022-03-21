/************************************************************************
 *                                                                      *
 *   format.c  Data Types - Qu. 4 Model Solution                        *
 *                                                                      *
 ************************************************************************/


#include <stdio.h>

int main(void)
{
	int number1;
	int number2;

	printf("\nThink of a number - any number!");
	scanf("%d", &number1);
	printf("\nNow choose another number.");
	scanf("%d",&number2);

	printf("You have chosen number1 = %d and number2 = %d\n", number1, number2);

	return 0;

}
