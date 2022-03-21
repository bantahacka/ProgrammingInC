/************************************************************************
 *                                                                      *
 *   prt_bits.c Further Data Types - Qu. 3 (Optional) Model Solution    *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

#define UNS_INT_BITS    (8 * sizeof(unsigned int))

#define HIGHBIT        ~((unsigned int )~0 >> 1)

void print_bits(unsigned int);

int main(void)
{
    int i = 2*2*2*2*2*2*2*2;

    print_bits(i);
    print_bits(65);
    print_bits(i + 12);
    print_bits(-i);
    print_bits(-65);

    return 0;
}

/*  VERSION 1  */

void print_bits(unsigned int num)
{
    unsigned int mask;
    printf("The number %u is\t ", num);
    for(mask =  HIGHBIT; mask != 0; mask >>= 1)
        printf("%u", (num & mask) != 0);
    printf(" in binary\n");
}


/* VERSION 2

void print_bits(unsigned int num)
{
    int i;
    unsigned int mask;
    printf("The number %u is\t ", num);
    for(mask = HIGHBIT, i = UNS_INT_BITS - 1; i >= 0; i--, mask = mask >> 1)
    {
        if (num & mask)
            printf("1");
        else
            printf("0");
    }
    printf(" in binary\n");
}

***************************************************************************/
