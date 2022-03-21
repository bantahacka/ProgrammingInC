/*********************************************************************
 *
 *  Filename:     READFILE.C
 *  Directory:    TREES\SOLUTION
 *
 *  Description:  This program reads words from a file. 
 *
 *                In this version, the program stores these words
 *                in a binary tree.
 *
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "treecode.h"


#define LONGEST_WORD    200

int  getNextWord(FILE* stream, char* buffer, int longest);
void process(FILE* stream);

int main(int argc, char* argv[])
{
    FILE * fp;
    char   fileName[80];

    /* Get the name of a file. If there is one on the command line,
     * use that, if not then prompt the user
     */
    if(argc == 1)
    {
        printf("File name to read ");
        fgets(fileName, sizeof(fileName) - 1, stdin);
        
        /* Lose the newline character at the end */
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

        exit(9);
    }
    
    /* process lines
     */
    process(fp);

    if(fp != stdin)
        fclose(fp);

    return 0;
} 


void process(FILE* stream)
{
    int     count = 0;
    NODE *  root = NULL; 
    char    buff[LONGEST_WORD];
    
    for(;;)
    {
        /* Get the current word
         */
        if(getNextWord(stream, buff, sizeof(buff)) == EOF)
            break;
            
        /* Insert into the tree
         */
        insertTree(&root, buff);
        
        /* Tell the user we're doing something
         */
        printf("%d words\r", count++);
    }
    /* Print out the tree
     */
    printTree(root);
    printf("\n");

}
  
  
int getNextWord(FILE* stream, char* buffer, int longest)
{
    int count;
    int ch;
    
    /* Skip past whitespace characters
     */
    while((ch = fgetc(stream)) != EOF && !isalpha(ch))
        ;

    for(count = 0;
        ch != EOF && isalpha(ch) && count < longest - 1;
        count++)
    {
        buffer[count] = (char)tolower(ch);
        ch = fgetc(stream);
    }
        
    buffer[count] = '\0';
    
    return (ch == EOF) ? EOF : !EOF;
} 
