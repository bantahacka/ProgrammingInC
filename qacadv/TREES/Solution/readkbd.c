/*********************************************************************
 *
 *  Filename:     READKBD.C
 *  Directory:    TREES\SOLUTION
 *
 *  Description:  This program reads words from the keyboard, and
 *                inserts them into a tree (the tree logic resides
 *                in TREECODE.C).
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treecode.h"

#define LONGEST_WORD    200

int main(void)
{
    NODE * root = NULL;           /* Root of the tree */
    char what[LONGEST_WORD];
        
    for(;;)
    {
        printf("Give me a string to insert ('x' to exit) ");
        fflush(stdin);
        scanf("%s", what);
        if (strcmp(what, "x") == 0)
            break;
        
        insertTree(&root, what);
            
        printf("The tree is now: ");
        printTree(root);
        printf("\n");
    }

    return 0;
}
