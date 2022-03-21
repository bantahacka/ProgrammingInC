/*********************************************************************
 *                                                                   
 *  Filename:     TRANS2.C
 *  Directory:    POINTERS\SOLUTION
 *
 *  Description:  This program carries out a simple translation of   
 *                characters typed at the keyboard. The program uses
 *                two command-line arguments to specify the character
 *                mappings required.
 *
 *                In this version of the program the command-line 
 *                strings may have different length.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TranslateStream (char *from, char *to);
int  TranslateChar   (char *from, char *to, char ch);

int main(int argc, char *argv[])
{
    char *from;
    char *to;

    switch (argc)
    {
    case 2:   from = argv[1];
              to   = "";
              break;

    case 3:   from = argv[1];
              to   = argv[2];
              break;

    default:  fprintf(stderr, "Usage: %s FromPattern ToPattern\n", argv[0]);
              exit(EXIT_FAILURE);
    }

    TranslateStream(from, to);
    return EXIT_SUCCESS;
}


void TranslateStream(char *from, char *to)
{
    int ch;

    while ( (ch=getchar()) != EOF)
    {
        ch = TranslateChar(from, to, (char)ch);
        if (ch != EOF)
            putchar(ch);
    }
}


/* 
 * This version of TranslateChar() copes with translation strings of
 * different lengths, and returns EOF if the translation maps to null
 */

int TranslateChar(char *from, char *to, char ch)
{
    char *p;

    if ( (p=strchr(from, ch)) == NULL)
    {
        return ch;
    }
    else
    {
        int idx   = p - from;
        int toLen = strlen(to);

        if (toLen == 0)
            return EOF;
        else if (idx > toLen - 1)
            return to[toLen - 1];
        else
            return to[idx];
    }
}
