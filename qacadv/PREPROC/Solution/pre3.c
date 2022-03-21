/*********************************************************************
 *                                                                   
 *  Filename:     PRE3.C
 *  Directory:    PREPROC\SOLUTION
 *
 *  Description:  Illustrates the use of __FILE__ and __LINE__
 *
 *********************************************************************/

#include <stdio.h> 

/* turn debug off by commenting out the following #define */
#define DEBUG

 
#if defined(DEBUG)
    #define PEXP(Expr) printf("%s(%d):%s = %d\n", __FILE__, \
                                                  __LINE__, \
                                                  #Expr,    \
                                                  (Expr));
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
