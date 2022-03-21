/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        putch.c                                               */
/*      DESCRIPTION: Program to illustrate the operation of putch()        */
/*                   and putchar() with respect to '\r' and '\n'           */
/*                                                                         */
/***************************************************************************/

#include <stdio.h>      /* For putchar()           */
#include <conio.h>      /* For putch() and getch() */

int main(void)
{
	/************************/
	/* Test putchar() first */
	/************************/
	printf ("\n\nputchar test\n");
	putchar('A');
	putchar('B');
	getch();

	/* putchar ('\r') just outputs '\r'   */
	/* ie AB will now be overwitten by CD */
	putchar ('\r');
	putchar('C');
	putchar('D');
	getch();

	/* putchar ('\n') however outputs  '\n' AND '\r' */
	/* ie output will be:   CD                       */
	/*                      EF                       */
	putchar ('\n');
	putchar('E');
	putchar('F');

	/************************/
	/* Now test putch()     */
	/************************/
	printf ("\n\nputch test\n");
	putch('a');
	putch('b');
	getch();

	/* putch ('\r') just outputs '\r'     */
	/* ie ab will now be overwitten by cd */
	putch ('\r');
	putch('c');
	putch('d');
	getch();

	/* putch ('\n') just outputs '\n'     */
	/* ie output will be:   cd            */
	/*                        ef          */
	putch ('\n');
	putch('e');
	putch('f');

    return 0;
}

