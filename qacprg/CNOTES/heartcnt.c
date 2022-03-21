#include <stdio.h>

struct Card
{
    char suit;
    int index;
};

int main (void)
{
	struct Card hand[5] =
                {{'c', 13}, {'h', 12}, {'d', 4}, {'h', 7}, {'s', 14}};         /*  Card array initialised */
	
	int i;	/* card index */
	int hc; /* heart counter */
	
	for (i = 0, hc = 0; i < 5; i++)
	{
		if (hand[i].suit == 'h')
		{
			hc++;
		}
	}
	
	printf("There are %d hearts\n", hc);

    return 0;
}
