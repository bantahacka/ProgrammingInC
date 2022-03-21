/*********************************************************************
 *                                                                   
 *  Filename:     READLINE.C
 *  Directory:    DYNMEM
 *
 *  Description:  This program reads one line of a file and displays it
 *                on the screen.
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

/* The process function itself. At the moment it does not do very much.
 * All it does do is to print out each character in the file.
 */
char * process(FILE* stream)
{
    int	c;

    while((c = fgetc(stream)) != EOF && c != '\n')
        putchar(c);

    return NULL;
}
