/************************************************************************
 *                                                                      *
 *   larger.c   Pointers and Functions - Qu. 2 Code Template            *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* PROTOTYPE of larger() HERE, PLEASE */

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

/* DEFINITION of larger() HERE, PLEASE */

