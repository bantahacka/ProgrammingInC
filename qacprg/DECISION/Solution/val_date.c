/************************************************************************
 *                                                                      *
 *   val_date.c   Decision Making - Qu. 4 (Optional) Model Solution     *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

int main(void)
{
    int          d, m, y;
    unsigned int z;
    int          date_ok = 0;

    while (!date_ok)        /* keep looping until date is ok */
    {
        printf("Please enter date (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &d, &m, &y);  

        /*
         *   Date Checks
         */
        if (y >= 1900 && y <= 2999) /* if year is ok */
	    {
	        switch(m)
            {
                case    2:  /* feb */
                    if (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0))
                        date_ok = d > 0 && d <= 29;
                    else
                        date_ok = d > 0 && d <= 28;
                    break;

		        case    4:  /* April */
                case    6:  /* June */
                case    9:  /* Sep */
                case    11: /* Nov */
                    date_ok  = d >= 1 && d <= 30;
                    break;

		        default:
                    date_ok =    m >= 1 && m <= 12
			                  && d >= 1 && d <= 31;
            }
	    }

	    if (!date_ok)       /* Entered bad date ? */
            printf("Bad date - try again!\n");
    }

    if (m < 3)
    {
        m += 12;
        d -= (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0)) ? 2 : 1;
    }

    z = 1 + d + (m * 2) + (3 * (m + 1) / 5) + y + y/4 - y/100 + y/400;
    
    switch(z % 7)
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
