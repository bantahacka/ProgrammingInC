/* Pointers and Structures - Passing Structures to Functions */

#include <stdio.h>

struct Date
{
	int day;
	int month;
	int year;
};

void print_date(struct Date *);

int main(void)
{
	struct Date today = {4, 1, 1986};
	print_date (&today);

	return 0;
}

void print_date(struct Date *date_ptr)
{
	printf ("Day = %d\n", date_ptr->day) ;
	printf ("Month = %d\n", date_ptr->month) ;
	printf ("Year = %d\n", date_ptr->year) ;
}
