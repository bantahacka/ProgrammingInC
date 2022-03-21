#include "defs.h"

int up(int a, int b)
{
	return a > b ;
}

int down(int a, int b)
{
	return b > a ;
}

void	funcOne(void)
{
	printf("hello from function funcOne\n");
}

void	funcTwo(void)
{
	printf("hello from function funcTwo\n");
}

void	funcThree(void)
{
	printf("hello from function funcThree\n");
}

void	funcFour(void)
{
	printf("hello from function funcFour\n");
}

void	funcFive(void)
{
	printf("hello from function funcFive\n");
}

void printNum(int i)
{
	printf("In printNum(): Value of num passed is %d\n", i);
}

int inc(int i)
{	
	return i + 1;
}