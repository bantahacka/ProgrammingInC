/*********************************************************************
 *
 *  Filename:     READKBD.C
 *  Directory:    TREES
 *
 *  Description:  This program reads ints from the keyboard, and
 *                inserts them into a tree (the tree logic resides
 *                in TREECODE.C).
 *
 *                Your task is to rewrite this program (and the tree 
 *                logic in TREECODE.C), to handle a tree of words
 *                rather than a tree of ints.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treecode.h"

int main(void)
{
    NODE * root = NULL;           /* Root of the tree */
    int    what;
        
    for(;;)
    {
        printf("Give me an integer to insert (-1 to exit) ");
        fflush(stdin);
        scanf("%d", &what);
        if (what == -1)
            break;
        
        insertTree(&root, what);
            
        printf("The tree is now: ");
        printTree(root);
        printf("\n");
    }

    return 0;
}


