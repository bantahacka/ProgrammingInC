/*********************************************************************
 *                                                                   
 *  Filename:     PRE5.C
 *  Directory:    PREPROC\SOLUTION
 *
 *  Description:  Uses a DEFINE_MAX macro which creates a max function
 *                for a certain type, which is provided as a parameter.
 *
 *                The CALL_MAX macro invokes this function with parameters.
 *
 *                The main benefit of this approach is that the parameters
 *                are only evaluated once when being passed into the  
 *                function, rather than being expanded potentially many 
 *                times (as in a macro).
 *
 *********************************************************************/

#include <stdio.h> 
 
#define DEFINE_MAX(type)      type  max_ ## type (type one, type two)   \
                              {                                         \
                                  return (one > two) ? one : two;       \
                              }                                         
        

#define CALL_MAX(type, a, b)  max_ ## type (a, b)



/* First, create a few instances of these functions */
DEFINE_MAX(int)
DEFINE_MAX(double)


int     main(void)
{ 
    int     i1=10,   i2=25,   i3;
    double  d1=10.0, d2=25.0, d3;
    
    printf("d1 = %.2f  d2 = %.2f\n",    d1, d2);
    printf("i1 = %d    i2 = %d\n\n\n",  i1, i2);
    
    d3 = CALL_MAX(double, d1, d2);
    printf("max_double(d1, d2) returns %.0f\n", d3);
    
    d3 = CALL_MAX(double, d1*10.0, d2+70.0);
    printf("max_double(d1*10.0, d2+70.0) returns %.0f\n", d3);
    
    i3 = CALL_MAX(int, i1, i2);
    printf("max_int(i1, i2) returns %d\n", i3);
    
    i3 = CALL_MAX(int, i1++, --i2);
    printf("max_int(i1++, --i2) returns %d\n\n", i3);
    
    printf("d1 = %.2f  d2 = %.2f\n",    d1, d2);
    printf("i1 = %d    i2 = %d\n\n\n",  i1, i2);
    
    return 0;
} 
