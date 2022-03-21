/*********************************************************************
 *
 *  Filename:     LISTCODE.H
 *  Directory:    LINKLIST
 *
 *  Description:  This file declares structs and functions for
 *                linked-list management (list of ints).
 *
 *********************************************************************/

typedef struct IntList
{ 
    int             data;               /* Data stored in this element  */
    struct IntList *next;               /* Pointer to next element      */
} NODE;

NODE * insertList(NODE * p, int value);
void   printList(NODE * head);
NODE * newListItem(int val);
 
