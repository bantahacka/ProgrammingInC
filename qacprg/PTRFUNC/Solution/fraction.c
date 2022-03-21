/************************************************************************
 *                                                                      *
 *   fraction.c Pointers/Functions - Qu. 4 (Optional) Model Solution    *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <math.h>               /* for floor standard function */

void fraction(double, int *, double *);

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

void fraction(double num, int *whole, double *part)
{
    *whole = (int) floor(num);

    *part =  num - floor(num);

}
