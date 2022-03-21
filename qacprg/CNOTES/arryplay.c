/* General pointer manipulation in an array */

#include <stdio.h>

int main(void)
{
	int a[5] = {46, 19, 77, 4, 1};
	int *aptr;
	int i = 2;

	aptr = a;    /* (or aptr = &a[0]) attach to a  */


	printf("%d\n", *(aptr + i));	/*  display 77 */
	
	aptr = aptr + 3;		/* move to 4  */

	printf("%d\n", (*aptr)++ );	/* display 4 then increment it */

	return 0;
}
