/************************************************************************
 *                                                                      *
 *   dynlarr.c   Pointer and Arrays - Qu. 8 (Optional) Model Solution   *
 *                                                                      *                                                                   *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>             /* for size_t, malloc and free */
#include <limits.h>             /* for INT_MAX                 */

void init_larray(long *, long);
void print_larray(long *, long);

int main(void)
{
    long * dynstart; /* Start of long array */

    long size = (long) INT_MAX;

    do
	{
        system ("cls");
        printf("Please type in the required array size\n");
        printf("The maximum allowed in %d\t", INT_MAX);
        scanf("%ld", &size);
	}
    while (size > (long)INT_MAX);

    dynstart = calloc(sizeof(long), (size_t) size);
    if (dynstart == NULL)        /* safety valve */
    {
        printf("Sorry %ld is too large, re-run the program\n", size);
        exit (-1);
    }

    init_larray(dynstart, size);

    print_larray(dynstart, size);

    free (dynstart);

    printf("\n\nIt worked!\n");
    return 0;
}

void init_larray(long * start, long size)
{
    long index = 0;
    long * lptr = start;
    long * end = start + size;
    
    while ( lptr < end )
    {
        *lptr++ = index++;
    }
}

void print_larray(long * start, long size)
{
    long * lptr = start;
    long * end = start + size;
    
    while ( lptr < end )
    {
        printf("%6ld", *lptr++);
    }
}
