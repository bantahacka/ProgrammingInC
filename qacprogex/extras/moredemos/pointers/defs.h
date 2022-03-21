#ifndef DEFS_H
#define DEFS_H

#include <stdio.h>
void doTestEvalPoints(void);

void constAndData(void);
void constAndPointers1(void);
void constAndPointers2(void);
void constAndPointers3(void);
void constAndPointers4(void);
void constAndPointers5(void);

void print2DArray1(int nA[][13], int rSize, int cSize);
void print2DArray2(int nA[][13], int rSize, int cSize);

void do2DArrays(void);
void doFuncPointers1(void);
void doFuncPointers2(void);
void doFuncPointers3(void);


int up(int a, int b);
int down(int a, int b);
void sortBy (int *pfirst, int *psecond, int (*how)(int a, int b));

void	funcOne(void);
void	funcTwo(void);
void	funcThree(void);
void	funcFour(void);
void	funcFive(void);

void (*getfFunc1(int which)) (void);

typedef void (* getfFuncType)(void);

void printNum(int i);
int inc(int i);

getfFuncType getfFunc2(int which);

extern void (*table[])(void);

#endif