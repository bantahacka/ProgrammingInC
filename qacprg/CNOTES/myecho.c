/* Input and Output - Command Line Argument Example

/* Program to echo command line arguments to standard output */
#include <stdio.h>

int main (int argc,  char *argv[])
{
	int i;
	for (i = 0 ; i < argc ; i++)
        printf ("%s%c", argv[i], (i < argc - 1) ? ' ' : '\n');

    return 0;
}
