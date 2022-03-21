/************************************************************************
 *                                                                      *
 *   val_date.c Functions - Qu. 4 (Optional) Model Solution             *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Function prototypes */
/* The order of declaration of the prototypes is unimportant */

int is_leap (int y);
int is_valid_date (int d, int m, int y);
int zellers (int d, int m, int y);
void print_day (int z);

int main(void)
{
    int d, m, y;

    do
    {
       /* Code for reading in the date */

       printf("Please enter date (DD/MM/YYYY): ");
       scanf("%d/%d/%d", &d, &m, &y);
    }
    while (!is_valid_date (d, m, y));

    print_day (zellers (d, m, y));
	printf("\n");

    return 0;

}


int is_leap (int y)
{
    return (y % 4 == 0 && (y % 400 == 0 || y % 100 != 0));
}


int is_valid_date (int d, int m, int y)
{
    int maxDays;

    if (y > 0 && m > 0 && d > 0 && m < 13)
    {
        if (m == 2)
        {
            maxDays = 28 + is_leap (y);
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            maxDays = 30;
        }
        else
        {
            maxDays = 31;
        }

        if (d <= maxDays)
        {
            return 1;
        }
    }

    return 0;
}


int zellers (int d, int m, int y)
{
    /*
     *   Add Your Code Here: to adjust the values of
     *   d, m and y under certain circumstances

     *                  d contains the day
     *                  m contains the month
     *                  y contains the year
     */

    int z;

    if (m == 1 || m == 2)
    {
        if (is_leap (y))
        {
            d = d - 2;
        }
        else
        {
            d = d - 1;
        }

        m = m + 12;
    }


    z = 1 + d + (m * 2) + (3 * (m + 1) / 5) + y + y/4 - y/100 + y/400;

    z %= 7;
    return z;
}

void print_day (int z)
{
    /*  Now, that case statement */
    switch (z)
    {
    case 0 : printf ("Sunday");       break;
    case 1 : printf ("Monday");       break;
    case 2 : printf ("Tuesday");      break;
    case 3 : printf ("Wednesday");    break;
    case 4 : printf ("Thursday");     break;
    case 5 : printf ("Friday");       break;
    case 6 : printf ("Saturday");     break;
    default: printf ("Invalid Day");  break;
    }
    return;
}


