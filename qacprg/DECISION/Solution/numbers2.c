/************************************************************************
 *                                                                      *
 *   numbers2.c Decision Making - Qu. 1 Model Solution                  *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int num;

    printf("Please enter number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Negative\n");

    if (num > 0)
        printf("Positive\n");

    if (num == 0)
        printf("Zero\n");

    /* Better to have written:
     *
     *   if (num < 0)
     *       printf("Negative\n");
     *   else if (num > 0)
     *       printf("Positive\n");
     *   else
     *       printf("Zero\n");
     */

     return 0;
}
