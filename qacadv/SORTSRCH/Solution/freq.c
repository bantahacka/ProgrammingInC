/*********************************************************************
 *                                                                   
 *  Filename:     FREQ.C
 *  Directory:    SORTSRCH\SOLUTION
 *
 *  Description:  This program breaks an input file into words and sorts
 *                them into an array. Only unique words are stored (requiring
 *                use of bsearch and qsort).
 *
 *********************************************************************/

#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <ctype.h>

#define LONGEST_WORD    200

int     getNextWord(FILE* stream, char* buffer, int longest);
void    addWordToList(char* word);
char ** process(FILE* stream);
int     strpcmp(const void* first, const void* second);



int main(int argc, char* argv[])
{
    int     i;
    FILE *  fp;
    char    fileName[80];
    char ** lines;

    /* Get the name of a file. If there is one on the command line,
     * use that, if not then prompt the user
     */
    if(argc == 1)
    {
        printf("File name to read ");
        fgets(fileName, sizeof(fileName) - 1, stdin);
        
        /* Loose the newline character at the end */
        fileName[strlen(fileName) - 1] = '\0';
    }
    else
    {
        strcpy(fileName, argv[1]);
    }

    /* If there is no file name then read from the standard input
     */
    if(fileName[0] == '\0')
    {
    	printf("reading from the standard input\n");
        fp = stdin;

    }
    else if((fp = fopen(fileName, "r")) == NULL)
    {
	/* If we can't open the file, kill the program
	 */
        printf("failed to open %s, %s (%d)\n",
                fileName, sys_errlist[errno], errno);

        return 9;
    }
    
    /* Read in all lines and sort
     */
    lines = process(fp);

    /* Then output
     */
    for(i = 0; lines[i] != NULL; i++)
        printf("%s\n", lines[i]);

    /* Then free
     */
    for(i = 0; lines[i] != NULL; i++)
        free(lines[i]);
        
    free(lines);    
    
    fclose(fp);
} 


char ** process(FILE* stream)
{
    int     wanted = 1;
    int     allocated = 0;
    char    buff[LONGEST_WORD];
    char *  p = buff;
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

        /* Get the current word
         */
        if(getNextWord(stream, buff, sizeof(buff)) == EOF)
            break;
            
        /* If this word is already in the list, ignore it and get
         * the next one.
         */
        if(bsearch(&p, lines, wanted - 1, sizeof(char*), strpcmp) != NULL)
            continue;                          

        /* Place it into dynamic memory
         */
        lines[wanted - 1] = _strdup(buff);
        
        /* Then sort
         */
        qsort(lines, wanted, sizeof(char*), strpcmp);
        
        wanted++;
	
    	printf("%d words\n", wanted);
    }

    /* Putting this NULL into the last entry but one means the
     * last line is easy to find (just like the last character in
     * a string)
     */
    lines[wanted - 1] = NULL;

    return lines;
}
  
  
int getNextWord(FILE* stream, char* buffer, int longest)
{
    int count;
    int ch;
    
    /* Skip past whitespace characters
     */
    while((ch = fgetc(stream)) != EOF && !isalpha(ch))
        ;

    for(count = 0; ch != EOF && isalpha(ch) && count < longest - 1;
                                count++) 
    {
        buffer[count] = (char)tolower(ch);
        ch = fgetc(stream);
    }
        
    buffer[count] = '\0';
    
    return (ch == EOF) ? EOF : !EOF;
} 


int strpcmp(const void* a, const void* b)
{
    const char* const* const one = a;
    const char* const* const two = b;
    
    return strcmp(*one, *two);
}
