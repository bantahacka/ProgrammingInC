#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int num = 10;

    /* Bitwise shift to left, answer should be 40 */
    printf("Num is now %d\n", num  << 2);

    /* Bitwise shift to right, answer should be 2 */
    printf("Num is now %d\n", num  >> 2);

    /* Bitwise NOT (1s complement), answer should be -11 */
    printf("Num is now %d", ~num);
    return 0;
}
