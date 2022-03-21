/************************************************************************
 *                                                                      *
 *   3of_kind.c   Pointers and Structures - Qu. 3 Model Solution        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

#define HAND_SIZE   5

struct Card
{
    char suit;      /* Suit: 'd', 'h', 'c' or 's' */
    int  index;     /* Card index: 2=2, ..., 13=King, 14=Ace */
};

struct  Card    hand[HAND_SIZE] =
{
    {'d', 12},  /* queen of diamonds */
    {'d', 11},  /* jack of diamonds  */
    {'c', 2 },  /* 2 of clubs        */
    {'h', 11},  /* jack of hearts    */
    {'c', 11}   /* jack of clubs     */
};

#define NO_THREE    -1

int three(struct Card *, int);

int main(void)
{
    int ret;

    ret = three(hand, HAND_SIZE);
    if (ret == NO_THREE)
        printf("No three of a kind found\n");
    else
        printf("There are three %ds\n", ret);

    return 0;
}

/*
 *   three   - trys to find a "three of a kind" in cards supplied
 *       - returns NO_THREE if no "three of a kind" is found else
 *         returns the 'index' value of the card
 */
	
/* VERSION 1 - using an array of counters */

int three(struct Card *cp, int size)
{
    int i;
    int occurrences[15];     /* we only use elements 2 to 14 */
    
    /* set all elements of array to 0 */    
    for(i = 2; i < 15; i++)
        occurrences[i] = 0;

    /* count how many of each card number we have */
    for(i = 0; i < size; i++, cp++)
        occurrences[cp->index] ++;

    /* check if any card is there 3 times */
    for(i = 2; i < 15; i++)
        if (occurrences[i] == 3)
            return i;

    return NO_THREE;
}

/* VERSION 2, using a nested loop and stopping
   as soon as three like cards are found  */

/***********************************************************************

int three(struct Card *cp, int size)
{
    int cardindex, count = 0;

    struct Card *max_cp = cp + size;
    struct Card *wrk_cp = cp;
    for(cardindex = 2; (cardindex < 15) && (count < 3); cardindex++)
    {
        for(count = 0, cp = wrk_cp;
            (cp < max_cp) && (count < 3);
	        cp++)
	    {
            if (cp->index == cardindex)
                count++;
	    }
    }
    if (cardindex == 15)
        return NO_THREE;
    else
        return (--cardindex);
}

***********************************************************************/

