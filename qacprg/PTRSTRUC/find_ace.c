/************************************************************************
 *                                                                      *
 *   find_ace.c   Pointers and Structures - Qu. 2 Code Template         *
 *                                                                      *
 ************************************************************************/

#include    <stdio.h>   /* Note : NULL defined in STDIO.H */

#define HAND_SIZE   5

struct Card
{
    char suit;      /* Suit: 'd', 'h', 'c' or 's' */
    int  index;     /* Card index: 2=2, ..., 13=King, 14=Ace */
};


/* hand is an array of 5 "struct Card"s */

struct  Card hand[HAND_SIZE] =
{
    {'d', 4},       /* four  of diamonds    */
    {'c', 9},       /* nine  of clubs       */
    {'h', 14},      /* ace   of hearts      */
    {'s', 10},      /* ten   of spades      */
    {'h', 8},       /* eight of hearts      */
};


struct Card * ace(struct Card *, int);


int main(void)
{
    struct Card *a;

    a = ace(hand, HAND_SIZE);
    if (a != NULL)
        printf("ace() returned %c %d\n", a->suit, a->index);
    else
        printf("No Ace found\n");

    return 0;
}

/* FUNCTION ACE HERE PLEASE */
