/************************************************************************
 *                                                                      *
 *   average.c   Pointers\Functions - Qu. 1 Code Template               *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* PROTOTYPE of average() here, with a return type void */

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

/* DEFINITION of average() here, please */
