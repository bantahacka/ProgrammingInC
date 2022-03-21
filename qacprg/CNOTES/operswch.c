/* Decision Making in C                         */
/* Multi-way Decision Making                    */
/*      - using the switch statement            */



/* Program using if else if construct to evaluate expressions   */
/* of the form    value operator value                          */

#include <stdio.h>

int main(void)
{
	float value1, value2;
	char operator;

    printf("Please type in your expression\n");
	scanf("%f %c %f", &value1, &operator, &value2);


	switch(operator)
	{
		case '+' : printf("%.2f\n", value1 + value2);
			       break;

		case '-' : printf("%.2f\n", value1 - value2);
			       break;

        case '*' : case 'x' : case 'X' :
                   printf("%.2f\n", value1 * value2);
			       break;

		case '/' : printf("%.2f\n", value1 / value2);
			       break;

		default  : printf("Unknown operator\n");
			       break;
	}

	return 0;
}
