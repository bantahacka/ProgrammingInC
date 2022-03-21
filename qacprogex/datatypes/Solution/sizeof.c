/************************************************************************
 *                                                                      *
 *   sizeof.c  Data Types - Qu. 6 Model Solution                        *
 *                                                                      *
 ************************************************************************/


#include <stdio.h>

int main(void)
{

	int ldble_size;

  	ldble_size = sizeof (long double);
	printf ("\n long double: %d bytes\n", ldble_size);

	return 0;
}
