#include <stdio.h>
#include <stdlib.h>
/* Using conditional statements */
/*
int main()
{
    const float ENG_LG = 1.3;
    const float ALLOW_LG = 0.23;
    const float ALLOW_SM = 0.15;
    float usr_eng = 0;
    unsigned int usr_mileage = 0;
    float allow_total = 0;

    printf("Enter your engine size in L (to 1 DP): ");
    scanf("%f", &usr_eng);

    printf("\nEnter your mileage to the nearest mile: ");
    scanf("%u", &usr_mileage);

    if (usr_eng < ENG_LG)
    {
        allow_total = usr_mileage * ALLOW_SM;
    }
    else
    {
        allow_total = usr_mileage * ALLOW_LG;
    }
    printf("\nYour allowance is %.2f", allow_total);

    return 0;
}
*/

/* Without using conditional statements */
int main()
{
    const float ALLOW_RATES[2] = {0.15, 0.23};
    unsigned int usr_sel = 0;
    unsigned int usr_mileage = 0;
    float allow_total = 0;

    printf("What size is your engine?");
    printf("\n[*]Greater than 1.3L (1)");
    printf("\n[*]Less than 1.3L (2): ");
    scanf("%u", &usr_sel);

    printf("\n Enter your mileage to the nearest mile: ");
    scanf("%u", &usr_mileage);

    allow_total = ALLOW_RATES[usr_sel-1] * usr_mileage;
    printf("\nYour allowance is %.2f", allow_total);

    return 0;
}
