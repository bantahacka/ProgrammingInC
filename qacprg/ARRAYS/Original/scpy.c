/************************************************************************
 *                                                                      *
 *   scpy.c    Arrays - Qu. 4 Code Template                             *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototype */

void scpy(char [], char []);

int main(void)
{
    char    s[100] = "1001001001001001001001001001001001001001";
    char    s1[]   = "Hi There";
    char    s2[22] = "22222222222222222222";

    scpy(s2, s1);
    printf("s2 is now: %s\n", s2);

    scpy(s, s2);
    printf("s is now: %s\n", s);

    return 0;
}


