/************************************************************************
 *                                                                      *
 *   avearray.c Pointer and Arrays - Qu. 6 (Optional) Model Solution    *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define SIZE 5

double avedarr(double *, int);
void scandarr(double *, int);

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

void scandarr(double *darray, int size)
{
    double *end = darray + size ;

    printf("Please type in %d doubles, separated by whitespace\n",size);
    while (darray < end)
    {
        scanf("%lf", darray++);
    }
}

double avedarr(double *darray, int size)
{
    double *end = darray + size ;
    double sum = 0.0;

    while (darray < end)
    {
        sum += *darray++;
    }

    return sum/size;
}


