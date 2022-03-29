/* Task 1: Count lines of text in a file. */
#include <stdio.h>
#include <stdlib.h>
#define FILENAME "test.txt"

int main()
{
    FILE *fp = NULL; // Declare & initialise file pointer
    char ch; // Declare character holder variable
    int linesCount = 0; // Declare and initialise line counter variable
    int linesOfText = 0; // **STRETCH** Declare an initialise line of text variable
    int isNextBlank = 0; // **STRETCH** Blank line flag
    fp = fopen(FILENAME, "r"); // Assign file to the pointer

    if(fp == NULL)
    {
        // File doesn't exist, throw an error and exit
        printf("File does not exist!\n");
        return -1;
    }

    // ** STRETCH** Iterate through the file until the end is reached
    while((ch = fgetc(fp)) != EOF)
    {
        // If blank line flag is 0
        if(isNextBlank == 0)
        {
            if(ch == '\n')
            {
                // ** STRETCH** Set flag to 1 so on the next iteration the blank line check is carried out. Increment lines of text.
                isNextBlank = 1;
                linesOfText++;
                linesCount++;
                continue;
            }
            else
            {
                // **STRETCH** The next character isn't a new line, next iteration
                continue;
            }
        }
        else
        {
            if(ch == '\n')
            {
                // **STRETCH** Found a blank line. Increment line count but not text count.
                linesCount++;
                continue;
            }
            else
            {
                // **STRETCH** The next character isn't a new line, next iteration and set the check flag to 0
                isNextBlank = 0;
                continue;
            }
        }
    }
    // Print total number of lines and close the file
    printf("Total number of lines (excluding blank lines): %d\n", ++linesOfText);
    printf("Total number of lines (including blank lines): %d\n", ++linesCount);
    fclose(fp);

    return 0;
}
