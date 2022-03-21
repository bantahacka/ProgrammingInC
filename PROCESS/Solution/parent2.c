/*********************************************************************
 *                                                                   
 *  Filename:     PARENT2.C
 *  Directory:    PROCESS\SOLUTION
 *
 *  Description:  This program invokes the child process CHILD.EXE
 *                with several command-line arguments.
 *
 *                The _execl() function is used to run the child process.
 *
 *********************************************************************/

#include <stdio.h>
#include <process.h>

int main(void)
{
    int comeBack;

    printf("Hello from the parent\n\n");

    comeBack = _execl("\\QACADV\\PROCESS\\DEBUG\\CHILD.EXE",
                     "parent-arg1", 
                     "parent-arg2",
                     "parent-arg3",
                      NULL);
           
    printf("\nHello again from the parent, value returned = %d\n", comeBack);
    printf("Press any key to exit the parent\n");
    getchar();

    return 0;
}
