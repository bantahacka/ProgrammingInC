/************************************************************************
 *                                                                      *
 *   prt_arr.c   Arrays - Qu. 1 Code Template                           *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototype for print_array */

void print_array(int [], int);

int main(void)
{
    int my_array[5] = { 7, 6, 5, 4, 3 };
    int other[7] = { 2, 4, 6, 8, 10, 12, 14 };

    print_array(my_array, 5);
    print_array(other, 7);

    return 0;
}   


/*  Function definition here */
