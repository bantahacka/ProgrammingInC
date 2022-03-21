/* Datatypes, Variables and Constants  - Types float, double and long double                                       */
#include <stdio.h>

int main(void)
{
	float         fl_rad, fl_area;
	double        db_rad, db_area;
	long double   ld_rad, ld_area;

	printf("Please type in a number\t");
	scanf("%f", &fl_rad);
	fl_area = 3.1415F * fl_rad * fl_rad;
	printf("%f\n", fl_area);

	printf("Please type in a number\t");
	scanf("%lf", &db_rad);
	db_area = 3.1415 * db_rad * db_rad;
	printf("%.14f\n", db_area);

	printf("Please type in a number\t");
	scanf("%Lf", &ld_rad);
	ld_area = 3.1415L * ld_rad * ld_rad;
	printf("%.20Lf\n", ld_area);

	return 0;
}

