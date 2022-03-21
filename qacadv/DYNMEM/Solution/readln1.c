/*********************************************************************
 *                                                                   
 *  Filename:     READLN1.C
 *  Directory:    DYNMEM\SOLUTION
 *
 *  Description:  This program reads one line of a file into dynamic
 *                memory before displaying it on the screen. A count is
 *                kept of the number of bytes allocated to the buffer, thus
 *                reducing the calls to realloc and increasing the speed of
 *                the routine.
 *
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "timer.h"

char * process(FILE*);


int main(int argc, char* argv[])
{
	FILE * fp;
	char   fileName[80];
	char * theLine;

	/* Get the name of a file. If there is one on the command line,
	 * use that, if not then prompt the user
	 */
    if(argc == 1) 
    {
        printf("File name to read ");
        scanf("%79s", fileName);
    }
    else
    {
        strcpy(fileName, argv[1]);
    }	

    /* If we cannot open the file, kill the program
     */
    if((fp = fopen(fileName, "r")) == NULL) 
    {
        printf("failed to open %s, %s (%d)\n",
                fileName, sys_errlist[errno], errno);

        exit(9);
    }
	

    /* Call the process function
     */
    theLine = process(fp);

    if(theLine != NULL)
    {
        printf("%s\n", theLine);
    	printf("%d characters\n", strlen(theLine));
    }
	
    /* Free the dynamic memory
	 */
	free(theLine);

	/* Close the file
	 */
	fclose(fp);

	return 0;
}

/* This version of process sits in a loop, calling realloc EVERY TIME a
 * character is read.
 */
char * process(FILE * stream)
{
	int    c;
	int    counter = 1;    /* Count of number of characters allocated */
	char * dyn = NULL;     /* Pointer to the allocated memory */

    for(;;) 
    {
        /* Allocate a block, one character larger than the current
         * block for the new character
         */
        dyn = realloc(dyn, counter * sizeof(char));

        if((c = fgetc(stream)) == EOF || c == '\n')
            break;
			
        dyn[counter - 1] = (char)c;
		
        counter++;
    }
    dyn[counter - 1] = '\0';

    return dyn;
}

