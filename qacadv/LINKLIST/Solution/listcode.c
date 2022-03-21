/*********************************************************************
 *
 *  Filename:     LISTCODE.C
 *  Directory:    LINKLIST\SOLUTION
 *
 *  Description:  This file contains linked-list code to insert
 *                an arbitrary number of WORDS into a sorted list. 
 *                Duplicate values are ignored.
 *
 *                In this version, we deal with a list of words
 *                rather than a list of ints.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listcode.h"

/* Insert a node into the list. The first parameter must be a pointer to
 * the first node in the chain. The value to insert is provided as the
 * second parameter.
 *
 * The return value is the head of the list, since this routine may be
 * required to change it.
 */
NODE * insertList(NODE * p, char *value)
{
    NODE * start = p;
    NODE * lag   = NULL;

    /* Find the position at which to insert the value
     */
    while(p != NULL && strcmp(p->data, value) < 0)
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
    if(p != NULL && strcmp(p->data, value) == 0)
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
        printf("%s ", head->data);
        head = head->next;
    }
    printf("\n");
}


/* Allocate storage for a node. Note that calloc is used, guaranteeing that
 * the node contains a NULL pointer to the next node.
 */
NODE * newListItem(char * val)
{
    static unsigned total = 0U;
    NODE * p;
    char * word;
    
    if((p = calloc(sizeof(*p), 1)) == NULL)
    {
        printf("ran out of dynamic memory allocating a node ");
        printf("(already allocated %u bytes)\n", total);
        exit(99);
    }
    total += sizeof(*p);

    if((word = _strdup(val)) == NULL)
    {
        printf("ran out of dynamic memory allocating a word ");
        printf("(already allocated %u bytes)\n", total);
        exit(100);
    }
    total += strlen(val) + 1;

    p->data = word;

    return p;
}
