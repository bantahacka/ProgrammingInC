#include <stdarg.h>
#include <stdio.h>

int average( int first, ... );

int main(void)
{
    /* Call with 3 integers (-1 is used as terminator). */
    printf( "Average is: %d\n", average( 2, 3, 4, -1 ) );

    /* Call with 4 integers. */
    printf( "Average is: %d\n", average( 5, 7, 9, 11, -1 ) );

    /* Call with just -1 terminator. */
    printf( "Average is: %d\n", average( -1 ) );

    return 0;
}

/* Returns the average of a variable list of integers. */

int average( int first, ... )
{
    int count = 0, sum = 0, i = first;
    va_list marker;

    va_start( marker, first );      /* Initialize variable arguments  */
    while( i != -1 )
    {
	    sum += i;
	    count++;
	    i = va_arg( marker, int);
    }
    va_end( marker );               /* Reset variable arguments       */
    return( sum ? (sum / count) : 0 );
}

