/************************************************************************
 *                                                                      *
 *   slen.c   Arrays - Qu. 3 Code Template                              *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototype */

int slen(char []);

int main(void)
{
    char    s1[]   = "Hi There";       /* string is 8 chars long */
    char    s2[29] = "This string is 28 chars long";

    printf("s1 is %d characters long\n", slen(s1));
    printf("s2 is %d characters long\n", slen(s2));

    return 0;
}


