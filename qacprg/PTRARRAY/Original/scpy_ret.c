/************************************************************************
 *                                                                      *
 *   scpy_ret.c Pointer and Arrays - Qu. 5 Code Template                *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define MAXLENGTH 40 

int slen(char *); 
void scpy(char *, char *);

int main(void)
{
    char str[MAXLENGTH];
	
    scpy(str, "Hello Again");      
    printf("Length after copying is %d\n", slen(str));

    return 0;
}


int slen(char *s)
{
    int i;

    for(i = 0; *s != '\0'; s++, i++)
        ;   /* Null statement */

    return i;
}

void scpy(char *d, char *s)
{
    while((*d++ = *s++) != '\0')
        ;       /* Null statement */

}

