/************************************************************************
 *                                                                      *
 *   power.c Functions - Qu. 3 Code Template (a working program)        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Function prototype */
/* Could also have used "double power(int number, int index); */

double power(int, int);

int main(void)
{
    int number;
    int index;
    double result;

    printf("Please enter number (integer) : ");
    scanf("%d", &number);

    printf("Please enter the power : ");
    scanf("%d", &index);

    result = power(number, index);
    printf("%d raised to the power %d is %.2f\n", number, index, result);

    /* Could have written: 
     *  printf("%d raised to the power %d is %.2f\n",
     *         num, index, power(number, index));
     */

     return 0;
}


double power (int x, int y )
{
    double sum ;
    int count ;

    for(sum = 1.0, count = 1; count <= y; count++)
    sum *= (double)x;

    return sum;
}

