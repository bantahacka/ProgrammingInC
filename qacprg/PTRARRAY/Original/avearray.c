/************************************************************************
 *                                                                      *
 *   avearray.c   Pointer and Arrays - Qu. 6 (Optional) Code Template   *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define SIZE 5

/* PROTOTYPES for avedarr() and scandarr() here */

int main(void)
{
    double da[SIZE];
    double ave = 0.0;

    scandarr(da, SIZE);         /* take SIZE doubles from keyboard */
                                /* into the array of doubles da    */

    ave = avedarr(da, SIZE);    /* Return the average  */

    printf("The average value is %f\n", ave);

    return 0;
}

/* Definitions of avedarr() and scandarr() here, please ! */
