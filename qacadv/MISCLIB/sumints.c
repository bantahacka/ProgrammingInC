/*********************************************************************
 *
 *  Filename:     SUMINTS.C
 *  Directory:    MISCLIB
 *
 *  Description:  This program uses the standard va_* marcos to
 *                effect the processing of a variable list of args
 *                sent to a function.
 *
 *                The PEXP macro from the much earlier Preprocessor lab
 *                is used to print out the variable lists.
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
