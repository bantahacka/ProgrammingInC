/* Pointers and Structures - Pointers, Arrays, Functions and Structures */
/* The file cards.c */

#include <stdio.h>
#include "cards.h"

int main(void)
{
	struct Card hand[SIZE] =
		{ {'s',14},{'c',7},{'d',4},{'c',12},{'h',13}};
	int count;

	count = count_hearts(hand, SIZE);
	printf("The number of hearts is %d\n", count);

	return 0;
}

int count_hearts(struct Card *cp, int size)
{
	int count;
	struct Card * end = cp + size;

	for (count = 0 ; cp < end ; cp++)
	{
		if (cp ->suit == 'h')
		{        
			count++;
		}
	}
	return count;
}

