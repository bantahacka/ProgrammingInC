/*********************************************************************
 *                                                                   
 *  Filename:     TRANS1.C
 *  Directory:    POINTERS\SOLUTION
 *
 *  Description:  This program carries out a simple translation of   
 *                characters typed at the keyboard. The program uses
 *                two command-line arguments to specify the character
 *                mappings required.
 *
 *                In this version of the program the command-line 
 *                strings must be the same length.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TranslateStream (char *from, char *to);
int  TranslateChar   (char *from, char *to, char ch);

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s FromPattern ToPattern\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strlen(argv[1]) != strlen(argv[2]))
    {
        fprintf(stderr, "Sorry, for this version the translation strings\n");
        fprintf(stderr, "must be of the same length\n");
        exit(EXIT_FAILURE);
    }

    TranslateStream(argv[1], argv[2]);

    return EXIT_SUCCESS;
}


void TranslateStream(char *from, char *to)
{
    int ch;

    while ( (ch=getchar()) != EOF)
    {
        ch = TranslateChar(from, to, (char)ch);
        putchar(ch);
    }
}


int TranslateChar(char *from, char *to, char ch)
{
    char *p;

    if ( (p=strchr(from, ch)) == NULL)
        return ch;
    else
        return to[ p-from ];
}
