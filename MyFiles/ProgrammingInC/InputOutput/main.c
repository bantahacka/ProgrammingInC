#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* Declare and initialise variables */
    int age = 0;
    float age2 = 0;

    /* Get users age */
    puts("How old are you?");

    /* %d means Denary Integer. &age means put the value %d into the address of the age variable. */
    scanf("%d", &age);

    /* Increment age by 1 */
    age++;

    /* Print result. No need to use & for the variable as we aren't putting data into the variable */
    printf("Next year you are %d years old.\n", age);

    /* Now lets play with floats */
    puts("Now enter your age as a decimal.");

    scanf("%f", &age2);

    age2++;

    /* %.2f means a float to 2 decimal places */
    printf("Next year you are %.2f years old.", age2);

    return 0;
}
