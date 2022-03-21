/************************************************************************
 *                                                                      *
 *   scpy.c Pointer and Arrays - Qu. 4 Model Solution                   *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define MAXLENGTH  20

void scpy1(char *, char *);
void scpy2(char *, char *);
void scpy3(char *, char *);
void scpy4(char *, char *);

int main(void)
{
    char source[MAXLENGTH + 1] = "Source String";
    char destination[MAXLENGTH + 1];

    scpy1(destination,source);
    printf("1. destination contains %s\n", destination);

    scpy2(destination,source);
    printf("2. destination contains %s\n", destination);

    scpy3(destination,source);
    printf("3. destination contains %s\n", destination);

    scpy4(destination,source);
    printf("4. destination contains %s\n", destination);

    return 0;
}



void scpy1(char *d, char *s)
{
    for(; *s != '\0'; s++, d++)
        *d = *s;

    *d = '\0';
}

void scpy2(char *d, char *s)
{
    while(*s != '\0')
        *d++ = *s++;

    *d = '\0';
}

void scpy3(char *d, char *s)
{
    while((*d++ = *s++) != '\0')
        ;       /* Null statement */
}

void scpy4(char *d, char *s)
{
    while(*d++ = *s++)   /* Implicit check against zero */
        ;       /* Null statement */
}

