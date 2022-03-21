/************************************************************************
 *                                                                      *
 *   slen.c    Pointer and Arrays - Qu. 3 Model Solution                *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#define MAXLENGTH  20

int slen1(char *);
int slen2(char *);
int slen3(char *);
int slen4(char *);

int main(void)
{
    char testname[MAXLENGTH + 1] = "13 chars long";

    printf("Length using slen1 is: %d\n",slen1(testname));
    printf("Length using slen2 is: %d\n",slen2(testname));
    printf("Length using slen3 is: %d\n",slen3(testname));
    printf("Length using slen4 is: %d\n",slen4(testname));

    return 0;
}


/* Four methods of writing slen() are given below */

int slen1(char *s)
{
    int i;

    for(i = 0; *s != '\0'; s++, i++)
        ;   /* Null statement */

    return i;
}

int slen2(char *s)
{
    int i;

    for(i = 0; *s++ != '\0'; i++)
        ;   /* Null statement */

    return i;
}


int slen3(char *s)
{
    char    *start = s;

    while(*s++ != '\0')
        ;

    return s - start - 1;
}


int slen4(char *s)
{
    char    *start = s;

    while(*s++)    /* Implicit check against zero */
        ;

    return s - start - 1;
}

