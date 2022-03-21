/************************************************************************
 *                                                                      *
 *   scpy_ret.c Pointer and Arrays - Qu. 5 Model Solution               *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define MAXLENGTH 40

int slen(char *); 
char *scpy(char *, char *);

int main(void)
{
    char str[MAXLENGTH];
	
    printf("Length after copying is %d\n", slen(scpy(str, "Hello Again")));

    return 0;
}


int slen(char *s)
{
    int i;

    for(i = 0; *s != '\0'; s++, i++)
        ;   /* Null statement */

    return i;
}

char *scpy(char *d, char *s)
{
    char *start = d;    /* Save starting address for return */

    while((*d++ = *s++) != '\0')
        ;       /* Null statement */

    return start;
}

