/*********************************************************************
 *                                                                   
 *  Filename:     CHILD.C
 *  Directory:    PROCESS\SOLUTION
 *
 *  Description:  This simple program prints out its command-line 
 *                arguments and then terminates.
 *
 *                (If only all programs were this easy!)
 *
 *********************************************************************/

#include <stdio.h>

int main (int argc, char *argv[])
{
    int i;

    fflush(stdout);
    printf("\n>> Hello from the child   %s\n", argv[0]);

    for (i = 1; i < argc; i++)
        printf(">> Child argv[%d] = %s\n", i, argv[i]);

    printf(">> Press any key to exit the child %s\n", argv[0]);
    getchar();

    return 98;
}
