/************************************************************************
 *                                                                      *
 *   weekday.c   Decision Making - Qu. 3 Code Template                  *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int d, m, y;
    unsigned int z;

    /* Code for reading in the date */
    printf("Please enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &d, &m, &y);  

    /*
     *   Add Your Code Here: to adjust the values of
     *   d, m and y under certain circumstances

     *                  d contains the day
     *                  m contains the month
     *                  y contains the year
     */


    z = 1 + d + (m * 2) + (3 * (m + 1) / 5) + y + y/4 - y/100 + y/400;

    z %= 7;

    /*  Now, that switch statement */


    return 0;
}
