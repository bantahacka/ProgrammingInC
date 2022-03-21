/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        enum.c                                                */
/*      DESCRIPTION: Program to illustrate the operation of enumerated     */
/*                   data types in C                                       */
/*                                                                         */
/***************************************************************************/
#include <stdio.h>

/* Define enum day */
enum day {mon = 1,     /* mon is 1  */
	  tue,         /* tue is 2  */
	  wed,         /* wed is 3  */
	  thu,         /* thu is 4  */
	  fri,         /* fri is 5  */
	  sat,         /* sat is 6  */
	  sun};        /* sun is 7  */

int main(void)
{
	/* Declare local variables of type  "enum day" */
	enum day today = mon;         /* ie set to 1   */
	enum day tomorrow;            /* uninitialised */

	printf ("Enter the day (mon = 1, tue = 2, etc)  ");
	scanf ("%d", &today);

	tomorrow = (today + 1) % 7;
	printf ("today = %d, tomorrow = %d\n", today, tomorrow);

    return 0;
}

