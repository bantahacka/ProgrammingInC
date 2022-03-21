/************************************************************************
 *                                                                      *
 *   fraction.c   Pointers/Functions - Qu. 4 (Optional) Code Template   *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <math.h>               /* for floor standard function */

/* PROTOTYPE of fraction here, please */

int main(void)
{
    double number;
    int whole = 1;
    double part = 0.0;

    printf("Please type in a number \t");
    scanf("%lf", &number);

    fraction(number, &whole, &part);
    printf("%f is made up from integer %d ", number, whole);
    printf(" and fractional part %f\n", part);

    return 0;
}

/* DEFINITION of fraction() here, please */
