/*********************************************************************
 *
 *  Filename:     TREECODE.C
 *  Directory:    TREES
 *
 *  Description:  This file contains binary tree code to insert ints
 *                into a binary tree, and perform general tree management.
 *
 *                Your task is to rewrite this code, to handle a tree
 *                of words rather than a tree of ints.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "treecode.h"


/* Insert a node into the tree. The first parameter must be a pointer to
 * a pointer to the root of the tree. The value to insert is the second
 * parameter.
 *
 * A pointer to a pointer is used because we will be required to alter the
 * pointer to the root.
 *
 * Duplicate values (ie. ones already present in the tree) are ignored.
 */
void insertTree(NODE ** p, int value)
{
    if(*p == NULL)
    {
    	*p = newTreeItem(value);
    }
    else if(value < (*p)->data)
    {
        insertTree(&((*p)->left), value);
    }
    else if(value > (*p)->data)
    {
        insertTree(&((*p)->right), value);
    }
    /* else we have found a duplicate and there is no need to place it
     * in the tree at all
     */
}


/* Print the Tree out. Will print downwards from whatever node is passed
 * in as the parameter. To print the whole tree, just pass in a pointer
 * to the root.
 */
void printTree(NODE * p)
{
    if(p != NULL)
    {
        printTree(p->left);         /* Print the left hand side  */
        printf("%d ", p->data);     /* Print this node           */
        printTree(p->right);        /* Print the right hand side */
    }
}


/* Allocate storage for a node. Note that calloc is used, guaranteeing that
 * the node contains a NULL pointer to the next node.
 */
NODE * newTreeItem(int val)
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
