/*********************************************************************
 *
 *  Filename:     READKBD.C
 *  Directory:    LINKLIST\SOLUTION
 *
 *  Description:  This program reads words from the keyboard, and
 *                inserts them into a linked list (the linked-list logic
 *                resides in LISTCODE.C).
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listcode.h"

#define LONGEST_WORD    200

int main(void)
{
    NODE * first = NULL;           /* First in the list */
    char what[LONGEST_WORD];
        
    for(;;)
    {
        printf("Give me a string to insert ('x' to exit) ");
        fflush(stdin);
        scanf("%s", what);
        if (strcmp(what, "x") == 0)
            break;
        
        first = insertList(first, what);
            
        printf("The list is now: ");
        printList(first);
    }

    return 0;
}


