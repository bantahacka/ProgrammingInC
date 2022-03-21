/************************************************************************
 *                                                                      *
 *   power.c Functions - Qu. 3 Model Solution                           *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Function prototype */
/* Could also have used "double power(double number, int index); */

double power(double, int);

int main(void)
{
    double number;
    int index;
    double result;

    printf("Please enter number (floating point) : ");
    scanf("%lf", &number);

    printf("Please enter the power : ");
    scanf("%d", &index);

    result = power(number, index);
    printf("%.2f raised to the power %d is %.2f\n", number, index, result);

    /* Could have written: 
     *  printf("%.2f raised to the power %d is %.2f\n",
     *         num, index, power(number, index));
     */

     return 0;
}


double power (double x, int y )
{
    double sum ;
    int count ;

    for(sum = 1.0, count = 1; count <= y; count++)
        sum *= x;

    return sum;
}

