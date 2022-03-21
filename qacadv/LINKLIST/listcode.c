/*********************************************************************
 *
 *  Filename:     LISTCODE.C
 *  Directory:    LINKLIST
 *
 *  Description:  This file contains linked-list code to insert
 *                ints into a linked list, and perform general linked-list
 *                management.
 *
 *                Your task is to rewrite this code, to handle a list 
 *                of words rather than a list of ints.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "listcode.h"


/* Insert a node into the list. The first parameter must be a pointer to
 * the first node in the chain. The value to insert is provided as the
 * second parameter.
 *
 * The return value is the head of the list, since this routine may be
 * required to change it.
 */
NODE * insertList(NODE * p, int value)
{
    NODE * start = p;
    NODE * lag   = NULL;

    /* Find the position at which to insert the value
     */
    while(p != NULL && p->data < value)
    {
        lag = p;
        p   = p->next;
    }

    /* First, cope with the situation where there is no list
     */
    if(p == NULL && lag == NULL)
    {
        /* Never got into the loop above
         */
        p = newListItem(value);
        return p;
    }

    /* Check for duplicates. If already found, no reason to
     * store again.
     */
    if(p != NULL && p->data == value)
        return start;

    /* Next, cope with the situation where we wish to insert
     * before the first item in the list
     */
    if(lag == NULL)
    {
        lag = newListItem(value);
        lag->next = p;
        return lag;
    }
    
    /* Finally, do a "normal" insert
     */
    lag->next = newListItem(value);
    lag->next->next = p;
    
    return start;
}


/* Print the list out. Will print forwards from whatever node is passed in
 * as the first parameter
 */
void printList(NODE * head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}


/* Allocate storage for a node. Note that calloc is used, guaranteeing that
 * the node contains a NULL pointer to the next node.
 */
NODE * newListItem(int val)
{
    NODE * p;
    
    if((p = calloc(sizeof(*p), 1)) == NULL)
    {
        printf("ran out of dynamic memory\n");
        exit(99);
    }
    p->data = val;

    return p;
}
