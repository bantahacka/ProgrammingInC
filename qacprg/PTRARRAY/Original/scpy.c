/************************************************************************
 *                                                                      *
 *   scpy.c    Pointer and Arrays - Qu. 4 Code Template                 *
 *   (same as scpy.sol Model Solution of Qu. 4 Arrays practical)        *                                                                   *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

void scpy(char [], char[]);

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


void scpy(char d[], char s[])
{
    int i;

    for(i = 0; s[i] != '\0'; i++)
        d[i] = s[i];

    d[i] = '\0';        /* Put the string terminator in. */
}

/******************** Another version ********************

void scpy(char d[], char s[])
{
    int i;

    for(i = 0; (d[i] = s[i]) != '\0'; i++)
        ;
}
**********************************************************/


