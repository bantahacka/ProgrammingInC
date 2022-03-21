/*********************************************************************
 *                                                                   
 *  Filename:     PRE1.C
 *  Directory:    PREPROC\SOLUTION
 *
 *  Description:  Illustrates the use of # and ## preprocessor operators
 *
 *********************************************************************/

#include <stdio.h> 
 
#define PEXP(Expr) printf("%s = %d\n", #Expr, (Expr));
 
int     main(void)
{ 
    int i=4,j=5; 
 
    PEXP(i); 
    PEXP(i+j); 
    PEXP(i*j); 

    return 0;
} 
