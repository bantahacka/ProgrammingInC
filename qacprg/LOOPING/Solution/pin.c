/************************************************************************
 *                                                                      *
 *   pin.c Looping Constructs - Qu. 2 Model Solution                    *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
	const int pin = 1234;
	int counter = 0;                 /* number of attempts  */
	int input = 0;                   /* used for user input */


	while (input != pin)
	{
		printf("Please enter your PIN\t");
		scanf("%d", &input);
		counter++;
	}

	printf("Well done, you remembered it!\n");
	printf("... and only after %d attempts\n", counter);

	return 0;
}
