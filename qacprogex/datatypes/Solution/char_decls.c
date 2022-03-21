/************************************************************************
 *                                                                      *
 *   char_decls.c  Data Types - Qu. 5 Model Solution                    *
 *                                                                      *
 ************************************************************************/



#include <stdio.h>

int main(void) 
{
	char testy;
	char test7;

	testy= 'y';
	test7= '7';

	printf("Letter %c has ASCII code %d.\n", testy, testy);
	printf("Number %c has ASCII code %d.\n", test7, test7);

	return 0;
}

/*
	
When compiled and run, the above program will print out:
	Letter y has the ASCII code 121.
	Number 7 has the ASCII code 55.
*/