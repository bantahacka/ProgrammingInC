/*********************************************************************
 *                                                                   
 *  Filename:     READFILE.C
 *  Directory:    DYNMEM\SOLUTION
 *
 *  Description:  This program uses the "process" routine from READLINE.SOL
 *                (renamed as "processLine") and calls it to read a whole
 *                file into dynamic memory.
 *
 *********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>


char ** process(FILE*);
char *  processLine(FILE*);


int main(int argc, char* argv[])
{
    int	i;
    FILE *	fp;
    char    fileName[80];
	char ** theLines;

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
    theLines = process(fp);

    /* Print out all the lines
     */
    for(i = 0; theLines[i] != NULL; i++)
        printf("%s\n", theLines[i]);

    /* Free the dynamic memory
     */
    for(i = 0; theLines[i] != NULL; i++)
        free(theLines[i]);

    free(theLines);

	/* Close the file
	 */
    fclose(fp);

    return 0;
}


char ** process(FILE * stream)
{
    int	wanted = 1;
    int	allocated = 0;
    char *  line;
    char ** lines = NULL;
	
    const int blocksize = 10;

    for(;;) 
    {
        /* Allocate a block, one char* larger than the current
         * block for the new line
         */
        if(allocated < wanted) 
        {
            allocated += blocksize;
            lines = realloc(lines, allocated * sizeof(char*));
        }

        /* Get this line
         */
        if((line = processLine(stream)) == NULL)
            break;
			
        lines[wanted - 1] = line;
		
        wanted++;
    }

    /* Putting this NULL into the last entry but one means the
     * last line is easy to find (just like the last character in
     * a string
     */
    lines[wanted - 1] = NULL;

    return lines;
}


/* This version reallocs in blocks. Only when the current block is exhausted
 * is realloc called to enlarge the block.
 */
/* This version reallocs in blocks. Only when the current block is exhausted
 * is realloc called to enlarge the block.
 */
char * processLine(FILE * stream)
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

    /* If we have hit the end of the file, and this was the first
     * character, then it really must be the end of the file (sometimes
     * files do not have a newline character before the end of file
     * character).
     */
    if(c == EOF && wanted == 1) 
    {
        free(dyn);
        return NULL;
    }

    return dyn;
}
