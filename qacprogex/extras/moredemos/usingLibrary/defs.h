#ifndef DEFS_H
#define DEFS_H
#include <stdio.h>
#include <string.h>
#include<time.h>
#include<math.h>
#include<stdarg.h>
#include <errno.h>
#include <assert.h>
#include <stdlib.h>

void doLineIO(void);
void doTime(void);
void doMaths(void);
void doVarArgs(void);
void doMisc(int argc, char* argv[]);
void doErrHand(void);

int sumNums(int, ...);
void my_exit(void);


#endif