/*      hashdefs.c      #define example */

#include <stdio.h>
#define BUF_SIZE 100

#define VAT 17.5
#define SUPER_VAT 1.5 + VAT

void example1(void);
void example2(void);

int main(void)
{
    example1();
    example2();

    return 0;
}

void example1(void)
{
    double buffer[BUF_SIZE];
    int i ;

    for (i = 0 ; i < BUF_SIZE; i++)
        buffer[i] = 0.0;

        
    for (i = 0 ; i < BUF_SIZE; i++)
        printf("%1.2f ", buffer[i]);

    printf("\n");
}


void example2(void)
{
    double amount;

    amount = SUPER_VAT * 21.50;

    printf("amount = %f", amount);
}
