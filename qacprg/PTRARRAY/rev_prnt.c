/************************************************************************
 *                                                                      *
 *   rev_prnt.c   Pointer and Arrays - Qu. 2 Code Template              *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define LONGSIZE 5

/* PROTOTYPE for rev_print_larray */

int main(void)
{
    long myarray[LONGSIZE]
                    = {100000L, 200000L, 300000L, 400000L, 500000L};
    
    rev_print_larray(myarray, LONGSIZE);

    return 0;
}

/* DEFINITION of rev_print_larray here */

