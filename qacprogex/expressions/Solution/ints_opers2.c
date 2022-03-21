/************************************************************************
 *                                                                      *
 *   ints_opers2.c  Expressions - Qu. 3 Model Solution                  *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int main(void)  
{
	/* declare local variables */
	int  tot_days;     /* total number of days            */
	int  whole_weeks;  /* calculate number of whole weeks */
	int  days_left;    /* calculate days left over        */

	/* prompt user for total number of days */
	printf ("Enter total number of days\n");
	scanf  ("%d", &tot_days);

	/* convert total days into weeks and days */
	whole_weeks = tot_days / 7;     /* rely on int division truncation */
	days_left   = tot_days % 7;     /* number of days outstanding */

	/* print total days in weeks/days */
	printf ("%d days is %d weeks, %d days\n", tot_days,
						  whole_weeks,
						  days_left);

	return 0;

}

/* VERSION 2 - no intermediate variables, 
   i.e no whole_weeks or days_left */
main_vers2()
{
	/* declare local variables */
	int  tot_days;     /* total number of days */

	/* prompt user for total number of days */
	printf ("Enter total number of days\n");
	scanf  ("%d", &tot_days);

	/* print total days in weeks/days */
	printf ("%d days is %d weeks, %d days\n", tot_days,
						  tot_days / 7,
						  tot_days % 7);

	return 0;
}

