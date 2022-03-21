/* Decision Making - Conditional Operator Example   */

#include <stdio.h>

int main(void)
{
	int num1 = 5, num2 = 3;
	int max_val;

	max_val = (num1 > num2) ? num1 : num2 ;
	printf("Max is %d\n", max_val);

	printf("Min is %d\n", (num1 < num2) ? num1 : num2) ;

	return 0;
}


