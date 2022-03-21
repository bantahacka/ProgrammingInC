/*********************************************************************
 *                                                                   
 *  Filename:     SIGNAL.C
 *  Directory:    PROCESS\SOLUTION
 *
 *  Description:  This program installs a signal handler to trap
 *                Control-C and Control-Break signals.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

volatile int interrupted = 0;

void handler(int);

int main(void)
{
    int line = 1;

    if(signal(SIGINT, handler) == SIG_ERR)
    {
        fprintf(stderr, "Could not set signal handler\n");
        return EXIT_FAILURE;
    }

    for (;;)
    {
        if (interrupted)
            break;

        fprintf(stderr, "%d program running ...\n", line++);
    }

    fprintf(stderr, "I've been interrupted 3 times now - OK, I give up!\n");
    getchar();
    return EXIT_SUCCESS;
}
    
    
void handler(int sig)
{
    static int count = 0;

    signal(sig, SIG_IGN);
    
    if (++count == 3)
    {
        count = 0;
        interrupted = 1;
    }
    signal(sig, handler);
}
