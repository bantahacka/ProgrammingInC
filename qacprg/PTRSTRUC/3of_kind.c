/************************************************************************
 *                                                                      *
 *   3of_kind.c   Pointers and Structures - Qu. 3 Code Template         *
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
 *           - returns NO_THREE if no "three of a kind" is found else
 *             returns the 'index' value of the card
 */
        
int three(struct Card *cp, int size)
{
    /* YOUR CODE HERE */
}



