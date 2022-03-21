/************************************************************************
 *                                                                      *
 *   leap.c Decision Making - Qu. 2 Model Solution                      *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int     y;  /* read the user specified year into this   */

    printf("Enter year (YYYY): ");
    scanf("%d", &y);

    if (y % 4 == 0 && y % 100 != 0)
        printf("Leap Year\n");
    else
        printf("NOT a leap year\n");

    return 0;
}
