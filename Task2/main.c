/* Task 2: Change all lower case characters to upper in a text file. */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define FILENAME "test.txt"

int main()
{
    FILE *fp = NULL; // Declare and initialise pointer for file to be read
    FILE *fp1 = NULL; // Declare and initialise pointer for temp file
    char ch;

    fp = fopen(FILENAME, "r"); // Open original file
    if(fp == NULL)
    {
        // File not found, print error and exit
        printf("File %s not found.", FILENAME);
        return -1;
    }

    fp1 = fopen("temp.txt", "w"); // Create temporary file
    if(fp1 == NULL)
    {
        // Unable to create temp file, print error and exit
        printf("Unable to create temporary file.");
        return -1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        // Iterate through file, if a character is lowercase change to upper case by taking 32 off its ASCII code then put into the temp file
        if(islower(ch))
        {
            ch = ch - 32;
        }
        fputc(ch, fp1);
    }
    // Close both files
    fclose(fp);
    fclose(fp1);

    // Remove the original file, rename the temp file to the original filename (creates a copy) then remove the temp file
    remove(FILENAME);
    rename("temp.txt", FILENAME);
    remove("temp.txt");

    // Open the new file
    fp = fopen(FILENAME, "r");
    if(fp == NULL)
    {
        // File not found, print error and exit
        printf("File %s not found.", FILENAME);
        return -1;
    }

    while((ch = fgetc(fp)) != EOF)
    {
        // Iterate through the file and print the characters on screen
        printf("%c", ch);
    }

    // Close the file and null the file handlers to ensure the files are released
    fclose(fp);
    fp = NULL;
    fp1 = NULL;

    return 0;
}
