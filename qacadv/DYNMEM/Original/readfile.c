/*********************************************************************
 *                                                                   
 *  Filename:     READFILE.C
 *  Directory:    DYNMEM
 *
 *  Description:  This program uses the "process" routine from the previous
 *                lab to place the file into dynamic memory.
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


char **	process(FILE * stream)
{
    char *  line;
	char ** lines = NULL;
	
    for(;;)
    {

        /* process a line at a time
         */
        if((line = processLine(stream)) == NULL)
            break;
			
        /* store that line via "lines"
		 */

    }

    /* Don't forget to append a NULL into lines
     */


    return lines;
}


char * processLine(FILE* stream)
{
    /* YOUR process ROUTINE FROM THE PREVIOUS EXERCISE */
}
