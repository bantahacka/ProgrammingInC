/************************************************************************
 *                                                                      *
 *   format_safer.c  Data Types - Qu. 4 Model Solution (safer version)  *
 *                                                                      *
 ************************************************************************/



#include <stdio.h>

int main(void)
{
	int number1;
	int number2;

	printf("\nThink of a number - any number!");
	scanf("%d%*c", &number1);			/* throws away enter char */
	printf("\nNow choose another number.");
	scanf("%d",&number2);

	printf("You have chosen number1 = %d and number2 = %d\n", number1, number2);

	return 0;

}
