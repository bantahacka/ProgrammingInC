/*********************************************************************
 *
 *  Filename:     SUMINTS.C
 *  Directory:    MISCLIB\SOLUTION
 *
 *  Description:  This program uses the standard va_* marcos to
 *                effect the processing of a variable list of args
 *                sent to a function.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

#define PEXP(Expr)	printf("%s returns %d\n", #Expr, Expr)


int SumList (int, ...);

int main(void)
{
    PEXP(SumList(2, 3, 0));
    PEXP(SumList(7, 1, 4, 0));
    PEXP(SumList(0));

    printf("The following don't work properly .... \n");

    PEXP(SumList(2, 3));              /* Missing 0 */
    PEXP(SumList(1, 9.9, 0.1, 0));    /* Bad types */

    return 0;
}
           
           
int SumList (int firstparam, ...)
{
   int     sum = 0;
   int     param = firstparam;
   va_list stackPointer;

   va_start(stackPointer, firstparam);

   while (param != 0)
   {
       sum  += param;
       param = va_arg(stackPointer, int);
   }
   va_end(stackPointer);

   return sum;
}
