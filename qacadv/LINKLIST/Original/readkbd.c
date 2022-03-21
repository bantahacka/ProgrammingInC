/*********************************************************************
 *
 *  Filename:     READKBD.C
 *  Directory:    LINKLIST
 *
 *  Description:  This program reads ints from the keyboard, and
 *                inserts them into a linked list (the linked-list logic
 *                resides in LISTCODE.C).
 *
 *                Your task is to rewrite this program (and the linked-
 *                list logic in LISTCODE.C), to handle a list of words
 *                rather than a list of ints.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listcode.h"

int main(void)
{
    NODE * first = NULL;           /* First in the list */
    int    what;
        
    for(;;)
    {
        printf("Give me an integer to insert (-1 to exit) ");
        fflush(stdin);
        scanf("%d", &what);
        if (what == -1)
            break;
        
        first = insertList(first, what);
            
        printf("The list is now: ");
        printList(first);
    }

    return 0;
}


