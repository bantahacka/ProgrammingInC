#include "defs.h"
void	(*table[])(void) = 
{
	funcOne,
	funcTwo,
	funcThree,
	funcFour,
	funcFive
};

int main(void)
{
	doTestEvalPoints();
	/*
	constAndPointers5();
	do2DArrays();
	doFuncPointers1();
	doFuncPointers2();
	doFuncPointers3();
	*/
	return 0;
}

void doTestEvalPoints(void)
{
	int i = 42;
	printNum(inc(i));
}

void do2DArrays(void)
{
	int timesTable[13][13] = {0};
	int row, col;
	int (*ttp)[13] = timesTable;
	

	for (row=1; row < 13 ; row++)
	{
		for(col=1; col < 13 ; col++)
		{
			/* timesTable[row][col] = row * col; */
			*(*(ttp + row) + col) = row * col;
		}
	}

	print2DArray2(ttp, 13, 13); 

}

void doFuncPointers1(void)
{

	int num1, num2;
	printf("Please type in two integers when prompted\n");
	printf("First number, please\t"); scanf("%d", &num1);
	printf("Second number, please\t"); scanf("%d", &num2);

	sortBy(&num1, &num2, up);
	printf("Order ascending is %d, %d\n", num1,  num2);

	sortBy(&num1, &num2, down);
	printf("Order descending is %d, %d\n", num1,  num2);

}



void sortBy(int *pfirst, int *psecond, int (*how)(int, int))
{
	int temp = 0;
	if (how(*pfirst, *psecond))
	{
		temp = *pfirst;
		*pfirst = *psecond;
		*psecond = temp;
	}
}

void	doFuncPointers2(void)
{
	int	i;
	
	/* Step 1. Find which function to invoke. It is very important to
	 * 	   check to see if the number is within the bounds of the
	 *	   array, otherwise we will start executing at some random
	 *	   address in memory and crash !!!!
	 */
	for(/*void*/; /*void*/; printf("\a\n\n")) 
	{
		printf("Please give me a number between 1 and 5: ");

		fflush(stdin);
		
		if(scanf("%d", &i) == 1 && i >= 1 && i <= 5)
			break;
	}
	
	/* Remember that the array goes from 0 to 4, not 1 to 5 */
	i = i - 1;

	(*(table[i]))();	/* Transfer control to function		*/
}

void	doFuncPointers3(void)
{
	int	i;
    getfFuncType funcNum	= NULL;

	for(/*void*/; /*void*/; printf("\a\n\n")) 
	{
		printf("Please give me a number between 1 and 5: ");

		fflush(stdin);
		
		if(scanf("%d", &i) == 1 && i >= 1 && i <= 5)
			break;
	}
	i = i -1;
	funcNum = getfFunc1(i);
	funcNum();
}

void (*getfFunc1(int which)) (void)
{
	void (*retFn) (void) = NULL;

	retFn = table[which]; 
	return retFn;
}

getfFuncType getfFunc2(int which)
{
	getfFuncType retFn = NULL;

	retFn = table[which]; 
	return retFn;
}

