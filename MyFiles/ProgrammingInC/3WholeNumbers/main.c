#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Declare and initialise 3 variables to hold the values */
    int num1, num2, num3, sum;
    float result;

    /* First number */
    puts("Enter the first number: ");
    scanf("%d", &num1);

    /* Second number */
    puts("\nEnter the second number: ");
    scanf("%d", &num2);

    /* Third number */
    puts("\nEnter the third number: ");
    scanf("%d", &num3);

    /* Do sum and show result*/
    sum = num1 + num2 + num3;
    printf("\nThe total is: %d", sum);

    /* Now get the average of the three numbers */
    result = sum / 3.0f;
    printf("\n\nThe mean average of %d is %.2f", sum, result);

    return 0;
}
