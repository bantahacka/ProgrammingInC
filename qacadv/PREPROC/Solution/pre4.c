/*********************************************************************
 *                                                                   
 *  Filename:     PRE4.C
 *  Directory:    PREPROC\SOLUTION
 *
 *  Description:  Expands PEXP macro to take an extra parameter (like
 *                printf in a way) so that any type can be handled.
 *
 *                The trick is to remove the %d from the printf string
 *                and give the user control over it.
 *
 *********************************************************************/

#include <stdio.h> 

/* turn debug off by commenting out the following #define */
#define DEBUG
 
#if defined(DEBUG)
    #define PEXP(Expr, STR)  printf("%s(%d):%s = %" #STR "\n", __FILE__, \
                                                               __LINE__, \
                                                               #Expr,    \
                                                               (Expr));
#else
    #define PEXP(Expr, STR) /* Nothing */
#endif
 
int     main(void)
{ 
    int    i=4,   j=5; 
    double a=4.0, b=5.0; 
 
    PEXP(i,   d);           /* Produces "%d" */
    PEXP(i+j, d); 
    PEXP(i*j, d); 

    PEXP(a,   .0f);         /* Produces "%.0f" - ie no decimal places */
    PEXP(a+b, .2f);         /* Produces "%.2f" - ie  2 decimal places */
    PEXP(a*b,   f);         /* Produces "%f"   - defaults to 6 places */

    return 0;

} 
