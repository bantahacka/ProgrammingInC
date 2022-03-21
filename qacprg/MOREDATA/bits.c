/************************************************************************
 *                                                                      *
 *    bits.c Build and run this program for the correct answers         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

#define BIT0    0x1     /* 0th bit set */
#define BIT1    0x2     /* 1st bit set */
#define BIT2    0x4     /* 2nd bit set */
#define BIT3    0x8     /* 3rd bit set */
#define BIT4    0x10    /* 4th bit set */

int main(void)
{
    unsigned int i = 8, j = 11;

    printf("test1: %u\n", i & j);
    printf("test2: %u\n", i | j);
    printf("test3: %u\n", i | 0);
    printf("test4: %u\n", i & 0);
    printf("test5: %u\n", i << 2);
    printf("test6: %u\n", BIT0 << 8);
    printf("test7: %u\n\n", (BIT3 | BIT4) >> 2);
    printf("bit0: %s\n", j & BIT0 ? "ON" : "OFF");
    printf("bit1: %s\n", j & BIT1 ? "ON" : "OFF");
    printf("bit2: %s\n", j & BIT2 ? "ON" : "OFF");
    printf("bit3: %s\n", j & BIT3 ? "ON" : "OFF");
    printf("bit4: %s\n", j & BIT4 ? "ON" : "OFF");

    return 0;
}
