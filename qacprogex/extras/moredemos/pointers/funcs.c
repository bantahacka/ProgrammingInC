#include "defs.h"
void constAndData()
{
	const int ci1 = 1089;			
	const int ci2; /* compiler warning */
	//ci1 ++; /* compiler error */

}
void constAndPointers1()
{
	int *const cpi1 = (int *)0XBAD;			
	int * const cpi2; /* compiler warning */
	//cpi1 = (int *)0XCAFE; /* compiler error */

}

void constAndPointers2()
{
	const int value = 1089;
	const int * pci1 = &value;			
	//(*pci1) ++;  /* compiler error */

}

void constAndPointers3()
{
	int value = 1089;
	const int * pci = &value;	/*variable data */		
	//(*pci) ++;  /*Compiler Error, even though value is variable */   
}
void constAndPointers4()
{
	const int value = 1089;
	int * pi = &value;	/*compiler warning */
	(*pi)++;
	printf("value is now %d\n", value);

}
void constAndPointers5()
{
	const int value = 1089;
	int * const cpi = &value;	/*const int - compiler warning */
   (*cpi)++;
	printf("value is now %d\n", value);

}

void print2DArray1(int nA[][13], int rSize, int cSize)
{
	int r,c;
	for (r=1; r < rSize ; r++)
	{
		for(c=1; c < 13 ; c++)
		{
			/* printf("%3d ", nA[r][c]); */
			printf("%3d ", *(*(nA + r) + c));
		}

				
		printf("\n");
	}

	return;
}

void print2DArray2(int (*nA) [13], int rSize, int cSize)
{
	int r,c;
	for (r=1; r < rSize ; r++)
	{
		for(c=1; c < 13 ; c++)
		{
			/* printf("%3d ", nA[r][c]); */
			printf("%3d ", *(*(nA + r) + c));
		}

				
		printf("\n");
	}

	return;
}

