/************************************************************************
 *                                                                      *
 *   prt_card.c   Pointers and Structures - Qu. 1 Code Template         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct Card
{
    char suit;      /* Suit:      'd', 'h', 'c' or 's'       */
    int  index;     /* Card index: 2=2, ..., 13=King, 14=Ace */
};


/* Insert Prototype here */

int main(void)
{
    struct Card q_of_c   = {'c', 12};
    struct Card two_of_d = {'d', 2};
    struct Card * card_ptr = &two_of_d;         /* Initialise pointer */
    
    print_card(card_ptr);                       /* call using pointer */
    print_card(&q_of_c);                        /* call using address */

    return 0;
}

/* and now the definition */

