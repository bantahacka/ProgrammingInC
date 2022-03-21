/************************************************************************
 *                                                                      *
 *   scpy3.c Pointer and Arrays - Qu. 4 Code Template part 2            *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define MAXLENGTH 40 

int slen(char *); 
void scpy2(char *, char *);

int main(void)
{
	char str[MAXLENGTH];
	
	scpy2(str, "Hello Again");      
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

void scpy2(char *d, char *s)
{
    while((*d++ = *s++) != '\0')
		;       /* Null statement */

}

