/* Arrays - Arrays in Action */

#include <stdio.h>

int days_in_month(int, int);
int is_leap(int);

int main(void)
{
	int m, y, days ;
	printf("Enter year, month\n");
	scanf("%d %d", &y, &m);

	days = days_in_month(m,y);
	printf("%d days\n", days);

        return 0;
}

int days_in_month(int mnth, int yr)
{
	int num_days[12] =
		{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	num_days[1] += is_leap(yr);  /* Cheeky use of Boolean */

	return num_days[mnth - 1];

}


int is_leap(int year)
{
	if (year % 4 == 0 && !(year % 100 == 0))
		return 1;
	else
		return 0;
}



