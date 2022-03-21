/* Pointers and Structures - Pointers, Arrays, Functions and Structures */
/* The file cards.h */

struct Card
{
	char suit;
	int index;
};

#define SIZE 5

int count_hearts(struct Card *, int);

