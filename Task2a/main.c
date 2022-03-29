/* Task 2a: Reverse each line of text */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define FILENAME "test.txt"
#define OUTFILE "temp.txt"
#define MARK_LEN 4
#define MARKER "<$}"

int check_reverse(FILE *);
void reverse_text(FILE *, FILE *);

int main()
{
    FILE *fp = NULL; // Declare and initialise pointer for file to be read
    FILE *fp1 = NULL; // Declare and initialise pointer for temp file
    int ch; // Declare holder for characters
    int check_rev;

    fp = fopen(FILENAME, "r"); // Open file
    if(fp == NULL)
    {
        // File not found, print error and exit
        printf("File %s not found.\n\n", FILENAME);
        return -1;
    }

    fp1 = fopen(OUTFILE, "w"); // Create temporary file
    if(fp1 == NULL)
    {
        // File not found, print error and exit
        printf("Unable to create temporary file.\n\n");
        return -1;
    }

    check_rev = check_reverse(fp);
    if(check_rev == 1)
    {
        while((ch = fgetc(fp)) != EOF)
        {
            printf("%c", ch);
        }
        fclose(fp);
        fclose(fp1);
    }
    else if(check_rev == 2)
    {
        printf("Reversing file %s.\n\n", FILENAME);
        reverse_text(fp, fp1);
        fclose(fp);
        fclose(fp1);
        remove(FILENAME);
        rename(OUTFILE, FILENAME);
        remove(OUTFILE);
    }
    else
    {
        printf("File %s empty or other unspecified error.\n\n", FILENAME);
        fclose(fp);
        fclose(fp1);
    }
    fp = NULL;
    fp1 = NULL;
    return 0;
}

int check_reverse(FILE *fp_check)
{
    char check_mark[4], *result;
    if((result = fgets(check_mark,MARK_LEN,fp_check)) != NULL)
    {
        if(strcmp(result, MARKER) == 0)
        {
            printf("Text in %s is reversed.\n\n", FILENAME);
            return 1;
        }
        else
        {
            printf("Text in %s is not reversed.\n\n", FILENAME);
            return 2;
        }
    }
    else
    {
        printf("File %s is empty.\n\n", FILENAME);
        return 3;
    }
}

void reverse_text(FILE *fp_from, FILE *fp_to)
{
    int i, pos;
    char ch;
    fputs(MARKER, fp_to);
    fseek(fp_from, 0, SEEK_END);
    pos = ftell(fp_from);
    // printf("Current position is %d", pos);
    i = 0;
    while (i<pos)
    {
       i++;
       fseek(fp_from,-i,SEEK_END);
       ch=fgetc(fp_from);
       fputc(ch, fp_to);
        printf("%c",ch);
    }
    printf("\n\nFile %s reversed.\n\n", FILENAME);
}