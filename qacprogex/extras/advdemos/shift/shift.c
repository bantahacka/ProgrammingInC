/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        shift.c                                               */
/*      DESCRIPTION: Program to illustrate right shift of unsigned ints    */
/*                   and of signed ints                                    */
/*                                                                         */
/*                   unsigned int right shifted:                           */
/*                       C GUARANTEES that top bit will be set to ZERO     */
/*                                                                         */
/*                   signed int right shifted:                             */
/*                       C DOES NOT SPECIFY whether the top bit will       */
/*                       retain its value to give the sign of the number   */
/*                                                                         */
/*       Clive Darke: 32 bit'ed                                            */
/*                                                                         */
/***************************************************************************/
#include <stdio.h>

int main(void)
{
	unsigned int u = 0xF0000000;        /* UNSIGNED INT, top bit is set */
	signed   int s = 0xF0000000;        /*   SIGNED INT, top bit is set */

	printf ("Right shift on UNSIGNED = %x\n", u>>1);
	printf ("Right shift on   SIGNED = %x\n", s>>1);

	return 0;
}
