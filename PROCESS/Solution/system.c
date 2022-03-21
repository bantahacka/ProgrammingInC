/*********************************************************************
 *                                                                   
 *  Filename:     SYSTEM.C
 *  Directory:    PROCESS\SOLUTION
 *
 *  Description:  This short program uses the system() call to print a
 *                directory. The only environment-specific thing here
 *                is the argument to system(), which has different 
 *                actions under different operating systems.
 *
 *                To make the program more portable, the preprocessor 
 *                is used to distinguish between Unix and other operating
 *                systems.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>  


#if UNIX
    #define CLEAR   "clear"
    #define LIST    "ls -l"
#else
    #define CLEAR   "cls"
    #define LIST    "dir"
#endif


int main(void)
{
    system(CLEAR);
    system(LIST);

    return 0;
}
