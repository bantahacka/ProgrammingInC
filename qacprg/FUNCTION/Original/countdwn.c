/************************************************************************
 *                                                                      *
 *   countdwn.c   Functions - Qu. 2 Code Template                       *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int getposint(void);
void downprint(int, int);

int main(void)
{
    int number = 0;
    int step = 2;

    number = getposint();           /* Get valid positive integer */
    downprint(number, step);        /* Display in steps of 2      */

    return 0;
}

/* Write the function definions here! */
