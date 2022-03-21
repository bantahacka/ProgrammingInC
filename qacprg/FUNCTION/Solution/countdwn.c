/************************************************************************
 *                                                                      *
 *   countdwn.c Functions - Qu. 2 Model Solution                        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int getposint(void);
void downprint(int, int);

int main(void)
{
    int number = 0;
    int step = 2;

    number = getposint();           /* Get valid positive integer */
    downprint(number, step);        /* Display in steps of 2      */

    return 0;
}

int getposint(void)
{
    int number = 0;

    do
    {
        printf("Please type in a positive number: \t");
        scanf("%d", &number);
    }
    while (number <= 0);

    return number;
}

void downprint(int number, int step)
{
	int counter = 0;

	for (counter = number; counter >= 0 ; counter -=step)
	{
		printf("%4d", counter);    /* a field width at least 4 */
	}

}
