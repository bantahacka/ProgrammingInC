/*********************************************************************
 *                                                                   
 *  Filename:     SIGNAL.C
 *  Directory:    PROCESS
 *
 *  Description:  This program installs a signal handler to trap
 *                Control-C and Control-Break signals.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>


int main(void)
{
    int line = 1;

    for (;;)
    {
        fprintf(stderr, "%d program running ...\n", line++);
    }

    fprintf(stderr, "I've been interrupted\n");
    getchar();
    return EXIT_SUCCESS;
}
