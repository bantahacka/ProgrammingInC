/************************************************************************
 *                                                                      *
 *   larger.c   Pointers and Functions - Qu. 2 Model Solution           *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

void larger(int *, int, int);

int main(void)
{
    int in1 = 3,
        in2 = -2,
        out;

    larger(&out, in1, in2);
    printf("%d\n", out);

    larger(&out, in1, 15);
    printf("%d\n", out);

    return 0;
}

void larger(int *p, int i1, int i2)
{
    if (i1 > i2)
        *p = i1;
    else
        *p = i2;

    /*  Could have written:
     *
     *   *p = (i1 > i2) ? i1 : i2;
     *
     */
}
