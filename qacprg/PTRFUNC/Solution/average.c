/************************************************************************
 *                                                                      *
 *   average.c   Pointers\Functions - Qu. 1 Model Solution              *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

void average (int, int, double *);

int main(void)
{
    int num1 = 0,
        num2 = 0;

    double  ave = 0.0;

	printf("Please type in two integers :\t");
    scanf("%d%d", &num1, &num2);

    average(num1, num2, &ave);

    printf("\nThe average of %d and %d is %.1f\n", num1, num2, ave);

    return 0;
}

void average(int n1, int n2, double *result)
{
    double ave = 0.0;

    ave = (double)(n1 + n2) * 0.5;
    *result = ave;
}

