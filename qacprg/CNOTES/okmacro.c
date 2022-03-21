/* The Preprocessor - Macros */

#include <stdio.h>

#define IS_LEAP(Y)  ((Y) % 4 == 0)
#define	DAYS_IN_FEB(YY)  (IS_LEAP(YY)?29:28)

int main(void)
{
    int d, y = 1995;
    double amount;

	if (IS_LEAP(1996))
        printf("Leap!!\n");

    d = DAYS_IN_FEB(y);

    amount = DAYS_IN_FEB(y+1) * 0.1;
	
    printf("Amount = %.2f\n", amount);  
	
    amount = DAYS_IN_FEB(y+2) * 0.1; 
	
    printf("Amount = %.2f\n", amount);

    return 0;
}
