/*********************************************************************
 *
 *  Filename:     TREECODE.H
 *  Directory:    TREES
 *
 *  Description:  This file declares structs and functions for
 *                binary tree management (binary tree of ints).
 *
 *********************************************************************/

typedef struct BinaryNode
{ 
    int                data;            /* Data stored in this element */
    struct BinaryNode *left;            /* Pointer to left subtree     */
    struct BinaryNode *right;           /* Pointer to right subtree	   */
} NODE;

void   insertTree(NODE ** p, int val);
void   printTree(NODE * head);
NODE * newTreeItem(int val);
