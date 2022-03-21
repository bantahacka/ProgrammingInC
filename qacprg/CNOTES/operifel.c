/* Decision Making in C                         */
/* Multi-way Decision Making                    */


/* Program using if else if construct to evaluate expressions   */
/* of the form    value operator value                          */

#include <stdio.h>

int main(void)
{
	float value1, value2;
	char operator;

    printf("Please type in your expression\n");
	scanf("%f %c %f", &value1, &operator, &value2);


	if (operator == '+')
		printf("%.2f\n", value1 + value2);

	else if (operator == '-')
		printf("%.2f\n", value1 - value2);

    else if (operator == '*' || operator == 'x' || operator == 'X')
		printf("%.2f\n", value1 * value2);

    else if (operator == '/')
		printf("%.2f\n", value1 / value2);

	else
		printf("Unknown operator\n");

	return 0;
}
