/*********************************************************************
 *                                                                   
 *  Filename:     DSTACK.C
 *  Directory:    MODULAR\SOLUTION
 *
 *  Description:  Implementation of the stack of 'doubles'
 *
 *********************************************************************/

#include "dstack.h"                 /* Include public DStack interface */

#define STACK_SIZE 100              /* Internal implementation details */

static double  Stk[STACK_SIZE];     /* The stack itself - simple array */
static double *pStk = Stk;          /* Note use of 'static' keyword    */


void StackInit(void)
{
    pStk = Stk;
}


void StackPush(double x)
{
    *pStk++ = x;
}


double StackPop(void)
{
    return *--pStk;
}
