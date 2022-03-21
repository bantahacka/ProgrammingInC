/************************************************************************
 *                                                                      *
 *   weekday.c Decision Making - Qu. 3 Model Solution                   *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int d, m, y;
    unsigned int z;

    /* Code for reading in the date */
    printf("Please enter date (DD/MM/YYYY): ");
    scanf("%d/%d/%d", &d, &m, &y);  

    if (m == 1 || m == 2)       /* could have used - if (m < 3) */
    {
        m += 12;
        if (y % 4 == 0 &&  (y % 400 == 0 || y % 100 != 0))
            d -= 2;
        else
            d -= 1;
    /*
     *  Could rewrite the if statement above like this:
     *
     *  d -= (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0)) ? 2 : 1;
     */
    }

	z = 1 + d + (m * 2) + (3 * (m + 1) / 5) + y + y/4 - y/100 + y/400;
    
    z %= 7;

    switch(z)
    {
        case 0:       
            printf("Sunday\n");
            break;
        case 1:       
            printf("Monday\n");
            break;
        case 2:       
            printf("Tuesday\n");
            break;
        case 3:       
            printf("Wednesday\n");
            break;
        case 4:       
            printf("Thursday\n");
            break;
        case 5:       
            printf("Friday\n");
            break;
        case 6:       
            printf("Saturday\n");
            break;
    }

    return 0;
}
