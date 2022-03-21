/************************************************************************
 *                                                                      *
 *   countdwn.c Looping Constructs - Qu. 3 Model Solution               *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int main(void)
{
	int number = 0;
	int counter = 0;

	do
	{
		printf("Please type in a positive number: \t");
		scanf("%d", &number);
	}
	while (number <= 0);

	for (counter = number; counter >= 0 ; counter -=2)
	{
		printf("%4d", counter);    /* a field width at least 4 */
	}

	return 0;
}

