#include "defs.h"
int sumNums(int n, ...)
{
	va_list args;
	int sum = 0;		/* assume list holds ints only - see below */

	va_start(args, n);
	while(n--) 
	{
		sum += va_arg(args, int);  /* cast to int */
	}

	va_end(args);

	return sum;

}

void my_exit(void)
{
	printf("End of program\n");
	fprintf(stderr, "errno is %d\n", errno);
}
