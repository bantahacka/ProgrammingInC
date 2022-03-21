#include <stdio.h>

struct Date
{
	int day ;
	int month ;
	int year ;
} ;

int valid_date(int d, int m, int y);

int main (void)
{
	struct Date date ;		/*  Local Date variable */
	printf ("Enter date as 3 numbers\n") ;
	scanf ("%d %d %d", &date.day, &date.month, &date.year) ;
	/*                 ^          ^            ^             */
	
	date.year++;		/* NOT Date.year++ */
	
	
	if (valid_date (date.day, date.month, date.year))
	{
		printf("Next year is %d/%d/%d\n", date.day, date.month, date.year);
		/*                                ^^^^      ^^^^        ^^^^      */	
	}
	else
	{
		printf("Sorry mate, your date is in a bad state!\n");
	}

    return 0;
}                                                           

int valid_date(int d, int m, int y)
{
	return 1; 			/* cop out!!! */
}
