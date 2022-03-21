/* Arrays - Array with Functions   */

#include <stdio.h>

void change(double []);            /* Prototype */

int main(void)
{
	double vector[5] =
		{0.0, 1.1, 2.2, 3.3, 4.4};

    change(vector);
    printf("%f %f\n", vector[0], vector[3]);

    return 0;
}

void change (double da[])
{
	da[0] = 3.14;            /* This is highly dangerous */
	da[3] = da[2] + da[4];
}

