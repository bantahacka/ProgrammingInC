/************************************************************************
 *                                                                      *
 *   larray.c   Pointer and Arrays - Qu. 1 Model Solution               *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#define LONGSIZE 5

void print_larray(long *, int);

int main(void)
{
    long myarray[LONGSIZE]
                    = {100000L, 200000L, 300000L, 400000L, 500000L};
    print_larray(myarray, LONGSIZE);

    return 0;
}

void print_larray(long * start, int size)
{
    long * lptr = start;    /* useful to preserve the start */
    long * end = start + size;

    while ( lptr < end )
	{
        printf("%ld\n", *lptr++);
    }
}


