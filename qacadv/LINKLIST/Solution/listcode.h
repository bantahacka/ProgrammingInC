/*********************************************************************
 *
 *  Filename:     LISTCODE.H
 *  Directory:    LINKLIST\SOLUTION
 *
 *  Description:  This file declares structs and functions for
 *                linked-list management (list of words).
 *
 *********************************************************************/

typedef struct WordList
{ 
    char *          data;               /* Data stored in this element  */
    struct WordList *next;              /* Pointer to next element      */
} NODE;

NODE * insertList(NODE * p, char * val);
void   printList(NODE * head);
NODE * newListItem(char * val);
 
