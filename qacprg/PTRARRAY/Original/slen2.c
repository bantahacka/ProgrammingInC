/************************************************************************
 *                                                                      *
 *   slen2.c   Pointer and Arrays - Qu. 3 Code Template                 *
 *   (same as slen.sol Model Solution of Qu. 3 Arrays practical)        *                                                                   *
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


int slen(char s[])
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
        ;   /* Null statement */

    return i;
}
