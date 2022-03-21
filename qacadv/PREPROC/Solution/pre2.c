/*********************************************************************
 *                                                                   
 *  Filename:     PRE2.C
 *  Directory:    PREPROC\SOLUTION
 *
 *  Description:  Illustrates the use of conditional compilation.
 *
 *********************************************************************/

#include <stdio.h> 

/* turn debug off by commenting out the following #define */
#define DEBUG

 
#if defined(DEBUG)
    #define PEXP(Expr) printf("%s = %d\n", #Expr, (Expr));
#else
    #define PEXP(Expr) /* Nothing */
#endif
 
int     main(void)
{ 
    int i=4,j=5; 
 
    PEXP(i); 
    PEXP(i+j); 
    PEXP(i*j); 

    return 0;
} 
