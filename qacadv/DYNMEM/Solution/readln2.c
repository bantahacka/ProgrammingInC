/*********************************************************************
 *                                                                   
 *  Filename:     READLN2.C
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

char * processVersion1(FILE*);
char * processVersion2(FILE*);


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
	

    /*****************************************************
     * Call the process function (version for Question 1)
     */
	printf("For version 1: ");

	timer(Start);
	theLine = processVersion1(fp);
	timer(Stop);

    if(theLine != NULL)
    	printf("%d characters\n", strlen(theLine));

    timer(Show);    /* How long did it take?   */
	free(theLine);  /* Free the dynamic memory */


    /*****************************************************
     * Call the process function (version for Question 2)
	 * Move the file pointer back to the start of the file. 
     * Otherwise, processVersion2 really will be quick!!
	 */
	printf("For version 2: ");
	rewind(fp);

    timer(Start);
	theLine = processVersion2(fp);
	timer(Stop);

    if(theLine != NULL)
    	printf("%d characters\n", strlen(theLine));

    timer(Show);    /* How long did it take?   */
	free(theLine);  /* Free the dynamic memory */


   	/* Close the file
	 */
	fclose(fp);

	return 0;
}

/* This version of process sits in a loop, calling realloc EVERY TIME a
 * character is read.
 */
char * processVersion1(FILE * stream)
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

/* This version reallocs in blocks. Only when the current block is exhausted
 * is realloc called to enlarge the block.
 */
char * processVersion2(FILE * stream)
{
    int    c;
    int    wanted = 1;     /* Count of number of characters wanted */
    int    allocated = 0;  /* Count of number of characters allocated */
    char * dyn = NULL;     /* Pointer to the allocated memory */
	
    const  int blocksize = 10;

    for(;;) 
    {
        /* Allocate a block, one character larger than the current
         * block for the new character
         */
        if(allocated < wanted) 
        {
            allocated += blocksize;
            dyn = realloc(dyn, allocated * sizeof(char));
        }

        if((c = fgetc(stream)) == EOF || c == '\n')
            break;
			
        dyn[wanted - 1] = (char)c;
		
        wanted++;
    }
    dyn[wanted - 1] = '\0';

    return dyn;
}
