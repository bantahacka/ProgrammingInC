/************************************************************************
 *                                                                      *
 *   prt_card.c  Pointers and Structures - Qu. 1 Model Solution         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct Card
{
    char suit;      /* Suit:      'd', 'h', 'c' or 's'       */
    int  index;     /* Card index: 2=2, ..., 13=King, 14=Ace */
};


void print_card(struct Card *);

int main(void)
{
    struct Card q_of_c   = {'c', 12};
    struct Card two_of_d = {'d', 2};
    struct Card * card_ptr = &two_of_d;         /* Initialise pointer */
    
    print_card(card_ptr);                       /* call using pointer */
    print_card(&q_of_c);                        /* call using address */

    return 0;
}

void print_card(struct Card *cp)
{
    printf("suit  = %c\n", cp->suit);
    printf("index = %d\n", cp->index);
}

