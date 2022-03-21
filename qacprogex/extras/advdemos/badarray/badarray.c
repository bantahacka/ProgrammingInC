/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        badarray.c                                            */
/*      DESCRIPTION: Program to illustrate NO BOUNDS CHECKING in C arrays! */
/*                                                                         */
/*      Please note: WILL CRASH DOS SYSTEM!!                               */
/*                                                                         */
/*  Clive Darke 04 January 2001 - modifications for Win32                  */
/*                now causes an exception in kernel.dll                    */
/*                                                                         */
/***************************************************************************/

#include <stdio.h>

int main(int argc, char *argv[])
{
    /* Declare local variables */
    int  a[] = {0, 1, 2, 3, 4};          /* 5 element array                */
    int  *pa = a;                        /* step thru array using pointers */

#ifdef WIN32
    char response = 'Y';                 /* user confirmation              */
    int  *pend = (int *)0xffffffff;      /* end pointer is TOP OF MEMORY!! */
#else
    char response;                       /* user confirmation              */
    int  *pend = (int *)0xffff;          /* end pointer is TOP OF MEMORY!! */

    /* Only run program if user wants to!! */
    printf ("Please note: WILL CRASH DOS SYSTEM! Do you want to continue? ");
    scanf ("%c", &response);

#endif

    if (response == 'Y'  ||  response == 'y')
    {
       /* Initialise all elements of array to 0 */
	    /* In fact, since pend is very large, all memory will be WIPED!! */
	    while (pa < pend)
       {
	        *pa++ = 0;
       }
    }

    return 0;
}
