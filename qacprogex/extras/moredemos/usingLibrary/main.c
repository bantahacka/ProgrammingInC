#include "defs.h"

int main(int argc, char*argv[])
{
	doLineIO();
	/*
	doTime();
	doMaths();
	doVarArgs();
	doErrHand();
	doMisc(argc, argv);
	*/
}

void doLineIO()
{
	char prompt[50+1];
	char name[50+1]="";
	FILE * fPrompt = NULL;
	FILE *fName = NULL;
	fPrompt = fopen("prompt.txt", "r");
	if (!fPrompt)
	{	
		fprintf(stderr, "Can’t open %s for reading.\n", "prompt.txt");
	}
	else
	{
		fgets(prompt, 50, fPrompt);
		printf("%s\n", prompt);
		fclose(fPrompt);

		fgets(name, 50, stdin);
		fName = fopen("name.txt", "w");
		if (!fName)
		{	
			fprintf(stderr, "Can’t open %s for writing.\n", "name.txt");
		}
		else
		{
			fputs(name, fName);
			fclose(fName);
			printf("All done!\n");
		}
	}
}

void doTime(void)
{
	time_t now;
	struct tm *pNowStr;
	char dateBuff[128];

	time(&now);
	printf("%s\n", ctime(&now));
	pNowStr = gmtime(&now);

    printf("%s\n", asctime(pNowStr));
	strftime(dateBuff, 128, "%c", pNowStr);
	printf("%s\n", dateBuff);
	printf("Month is %d\n", pNowStr->tm_mon);
}

void doMaths(void)
{
	double num1 = -4.6;
	double num2=4.6;
	double num2Fraction = 0.0;
	double num2Whole = 0.0;
	double num2Mantissa = 0.0;
	int num2Exponent = 0;
	printf("floor(-4.6) is %f and ceil(-4.6) is %f\n", floor(num1), ceil(num1));
	num2Whole = modf(num2, &num2Fraction);
	printf("Using modf() to split 4.6, gives %f and %f\n",num2Whole , num2Fraction);
	num2Mantissa = frexp(num2, &num2Exponent);
	printf("Using frexp() mantissa and exponent of 4.6 is %f and %d\n", num2Mantissa , num2Exponent);
    printf("10.0 X 2^5 is %f\n", ldexp(10.0, 5));
	
}
void doVarArgs(void)
{
	int numOfNums1=4, numOfNums2=7;
	int tot1 = sumNums(numOfNums1, 1, 2 , 3, 4);
	int tot2 = sumNums(numOfNums2, 1, 2, 3, 1, 2, 3, 10);
	printf("tot1 is %d and tot2 is %d\n", tot1, tot2);


}

void doErrHand()
{
	FILE * fp;
    char * fileName;
	fileName = (char *) malloc(sizeof (char) * 30);
	strcpy(fileName, "c:\\test.txt");

	atexit(my_exit);

	assert(fileName != NULL);

	fp =fopen(fileName, "r");
	if (fp == NULL)
	{
		printf("errno is %d\n", errno);
		perror("data.txt");
		errno = 0;
	}

}

void doMisc(int argc, char*argv[])
{
	int num1 = 0;
	double num2 = 0.0;
	switch (argc)
	{
	case 0: case 1: 
			printf("Please enter two arguments (at least)\n");
			break;
	case 2: 
			num1 = abs(atoi(argv[1]));
			printf("Absolute value of %s incremented is %d\n", argv[1], ++num1);
			break;
	case 3:
			num1 = atoi(argv[1]);
			num2 = atof(argv[2]);
			printf("%f raised to the power %d is %f\n", num2, num1, pow(num2, num1));
			break;
	}
	return;
}