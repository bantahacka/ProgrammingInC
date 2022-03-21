/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        sizeof.c                                              */
/*      DESCRIPTION: Program to illustrate size of constants in C          */
/*                                                                         */
/***************************************************************************/
#include <stdio.h>

int main(void)
{
    printf ("sizeof (10)    = %d\n", sizeof (10));
    printf ("sizeof (-10)   = %d\n", sizeof (-10));
    printf ("sizeof (10U)   = %d\n", sizeof (10U));
    printf ("sizeof (10L)   = %d\n", sizeof (10L));
    printf ("sizeof (10UL)  = %d\n", sizeof (10UL));

    printf ("sizeof (010)   = %d\n", sizeof (010));
    printf ("sizeof (0x10)  = %d\n", sizeof (0x10));
    printf ("sizeof (32768) = %d\n", sizeof (32768));
    printf ("sizeof (66000) = %d\n", sizeof (66000));

    printf ("sizeof (10.0)  = %d\n", sizeof (10.0));
    printf ("sizeof (10.0F) = %d\n", sizeof (10.0F));
    printf ("sizeof (10.0L) = %d\n", sizeof (10.0L));

    return 0;
}

