/*********************************************************************
 *
 *  Filename:     TREECODE.H
 *  Directory:    TREES\SOLUTION
 *
 *  Description:  This file declares structs and functions for
 *                binary tree management (binary tree of words).
 *
 *********************************************************************/

typedef struct BinaryNode
{ 
    char *            data;             /* Data stored in this element */
    struct BinaryNode *left;            /* Pointer to left subtree     */
    struct BinaryNode *right;           /* Pointer to right subtree	   */
} NODE;

void   insertTree(NODE ** p, char * val);
void   printTree(NODE * head);
NODE * newTreeItem(char * val);
