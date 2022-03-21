/************************************************************************
 *                                                                      *
 *   sqr.c Looping Constructs - Qu. 5 (Optional) Model Solution         *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int     value;      /* used to read in user specified number */
    int     bump;       /* use this to go through odd numbers    */
    double  sum;        /* accumulate square into this variable  */
    int     i;          /* loop counter                          */

    /* Read in number to square */
    printf("Enter number to square:");
    scanf("%d", &value);    

    /* Now loop around accumulating odd numbers into sum */
    sum = 0.0;
    i = 0;
    bump = 1;
    while(i < value)
    {
        sum += (double)bump;
	    i++;
        bump += 2;
    }


    /* Note: the loop and initialisation above could also have
     *  been written as a for loop:
     *
     *   for(sum = 0.0, i = 0, bump = 1; i < value; i++, bump += 2)
     *       sum += (double)bump;
     *
     *  Or even as:
     *
     *   for(sum = 0.0, bump = 1; value-- > 0; bump += 2)
     *       sum += (double)bump;
     */

    printf("%f\n", sum); 

    return 0;
}
