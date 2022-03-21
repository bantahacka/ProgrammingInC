/*********************************************************************
 *
 *  Filename:     AVLDEMO.C
 *  Directory:    TREES\AVL
 *
 *  Description:  This file contains all of the AVL code in the Trees 
 *                chapter in the Advanced C course.
 *
 *                In addition, there are a few utility functions 
 *                (e.g. to print the tree in LEVEL order rather than 
 *                preorder, postorder or other strange order).
 *
 *                There is also a test harness.
 *
 *********************************************************************/

#include <stdio.h>	/* printf, getchar */
#include <ctype.h>	/* tolower         */
#include <stdlib.h>	/* calloc          */

#define	TRUE	(1)
#define	FALSE	(0)


/* The core structure of the program
 */
typedef  struct	tree_node 
{
	int	value;
	int	bf;
	struct	tree_node*	left;
	struct	tree_node*	right;
} AVLnode;


void treeToArray(AVLnode*, int, AVLnode*[]);


AVLnode * newNode(int val)
{
	AVLnode * p;
	
	if((p = calloc(1, sizeof(AVLnode))) == NULL) 
    {
		fprintf(stderr, "ran out of dynamic memory\n");
		exit(9);
	}
	/* Note that using calloc saves us initialising "bf", "left" and
	 * "right", since these will all be zero.
	 */
	p->value = val;
	return p;
}

void deleteNode(AVLnode* p)
{
	free(p);
}

/* The left and right rotation functions could probably be coallesced into
 * one which was passed another parameter saying "left" or "right". However
 * this one function would be so messy ....
 */
void left_rotation(AVLnode** parent,  int  insert,  int* unbalanced)
{
	int	      childBf;
	AVLnode * grandChild;
	AVLnode * child;

	child      = (*parent)->left;
	childBf    = child->bf;
	grandChild = child->right;

	if(childBf == 1 || (childBf == 0 && grandChild->bf == -1)) 
    {

		/* LL? rotation
		 */
		(*parent)->left = child->right;	
		child->right    = *parent;

		if(childBf == 0) 
        {	
			/* LL' rotation
			 */
			(*parent)->bf = +1;
			(*parent)     = child;
			(*parent)->bf = -1;
		} 
        else 
        {
			/* LL rotation
			 */
			(*parent)->bf = 0;
			(*parent)     = child;
			(*parent)->bf = 0;

			/* remove imbalance
			 */
			*unbalanced = FALSE;
		}
	} 
    else
    {
		/* LR? rotation
		 */
		child->right      = grandChild->left;
		grandChild->left  = child;
		(*parent)->left   = grandChild->right;
		grandChild->right = *parent;

		if(childBf == 0) 
        {
			/* LR' rotation
			 */
			switch(grandChild->bf) 
            {
			  case 1:
				(*parent)->bf = -1;
				child->bf     = 1;
				break;
			  case 0:
				(*parent)->bf = 0;
				child->bf     = 1;
				break;
			}
		} 
        else 
        {
			/* LR rotation
			 */
			switch(grandChild->bf) 
            {
			  case 1:
				(*parent)->bf = -1;
				child->bf     = 0;
				break;
			  case 0:
				(*parent)->bf = 0;
				child->bf     = 0;
				break;
			  case -1:
				(*parent)->bf = 0;
				child->bf     = 1;
				break;
			}
			*unbalanced = FALSE;
		}
		*parent       = grandChild;
		(*parent)->bf = (childBf == 0) ? 1 : 0;
	}
	/* deletion inverts the sense of imbalance
	 */
	if(!insert)
		*unbalanced = !*unbalanced;
}


void right_rotation(AVLnode** parent, int insert, int* unbalanced)
{
	int	      childBf;
	AVLnode * grandChild;
	AVLnode * child;

	child      = (*parent)->right;
	childBf    = child->bf;
	grandChild = child->left;

	/* RR? rotation
	 */
	if(childBf == -1 || (childBf == 0 && grandChild->bf == 1)) 
    {

		(*parent)->right = child->left;
		child->left      = *parent;

		if(childBf == 0) 
        {
			/* RR' rotation
			 */
			(*parent)->bf = -1;
			(*parent)     = child;
			(*parent)->bf = +1;
		}
        else
        {
			/* RR rotation
			 */
			(*parent)->bf = 0;
			(*parent)     = child;
			(*parent)->bf = 0;
			*unbalanced   = FALSE;
		}
	} 
    else
    {
		/* RL? rotation
		 */
		child->left       = grandChild->right;
		grandChild->right = child;
		(*parent)->right  = grandChild->left;
		grandChild->left  = *parent;

		if(childBf == 0) 
        {
			/* RL' rotation
			 */
			switch(grandChild->bf) 
            {
			  case -1:
				(*parent)->bf = 1;
				child->bf     = -1;
				break;
			  case 0:
				(*parent)->bf = 0;
				child->bf     = -1;
				break;
			}
		} 
        else
        {
			/* RL rotation
			 */
			switch(grandChild->bf) 
            {
			  case -1:
				(*parent)->bf = 1;
				child->bf     = 0;
				break;
			  case 0:
				(*parent)->bf = 0;
				child->bf     = 0;
				break;
			  case 1:
				(*parent)->bf = 0;
				child->bf     = -1;
				break;
			}
			*unbalanced = FALSE;
		}
		*parent       = grandChild;
		(*parent)->bf = (childBf == 0) ? -1 : 0;
	}
	/* deletion reverses the sense of balance
	 */
	if(!insert)
		*unbalanced = !*unbalanced;
}


void avl_insert(AVLnode** parent, int value, int* unbalanced)
{
	if(*parent == NULL) 
    {
		
		/* Insert the element here
		 */
		*unbalanced = TRUE;
		*parent     = newNode(value);

	}
    else if(value < (*parent)->value) 
    {

		avl_insert(&(*parent)->left, value, unbalanced);

		/* Left branch has grown higher
		 * Need to INCREASE the BF by 1
		 */
		if(*unbalanced) 
        {	
			switch((*parent)->bf) 
            {	
			  case -1:
				/* BF of -1 becomes 0
				 */
				(*parent)->bf = 0;

				/* tree now balanced
				 */
				*unbalanced = FALSE;
				break;
			  case 0:
				/* BF of 0 becomes 1
				 */
				(*parent)->bf = 1;
				break;
			  case 1:
			  	/* BF of +2, rotate left
				 */
				left_rotation(parent, TRUE, unbalanced);
				break;
			}
		}

	} 
    else if(value > (*parent)->value) 
    {

		avl_insert(&(*parent)->right, value, unbalanced);
		if(*unbalanced) 
        {

			/* Right branch has grown higher
			 * Need to DECREASE the BF by 1
			 */
			switch((*parent)->bf) 
            {
				
			  case 1:
				/* BF of 1 becomes 0
				 */
				(*parent)->bf = 0;

				/* tree now balanced
				 */
				*unbalanced = FALSE;
				break;
			  case 0:
				/* BF of 0 becomes -1
				 */
				(*parent)->bf = -1;
				break;
			  case -1:
				/* BF of -2, rotate right
				 */
				right_rotation(parent, TRUE, unbalanced);
				break;
			}
		}
	} 
    else 
    {
		/* The value is already present in the tree. If there
		 * were a reference count, we would increment it here
		 */
		*unbalanced = FALSE;
	}
}

void avl_delete(AVLnode** parent, int  deleteVal, int* unbalanced)
{
	static	int	static_local_destroy = TRUE;

	/* Value not found in tree
	 */
	if(*parent == NULL) 
    {
		*unbalanced = FALSE;
		return;

	} 
    else  if(deleteVal < (*parent)->value) 
    {

		avl_delete(&(*parent)->left, deleteVal, unbalanced);

		if(*unbalanced)
        {
            /* Left branch has become lower
			 */
			switch((*parent)->bf) 
            {
			  case 1:
				(*parent)->bf = 0;
				break;
			  case 0:
				(*parent)->bf = -1;
				*unbalanced   = FALSE;
				break;
			  case -1:
				right_rotation(parent, FALSE, unbalanced);
				break;
			}
        }

	} 
    else if(deleteVal > (*parent)->value) 
    {

		avl_delete(&(*parent)->right, deleteVal, unbalanced);

		if(*unbalanced)
        {
			/* Right branch has become lower
			 */
			switch((*parent)->bf) 
            {
			  case -1:
				(*parent)->bf = 0;
				break;
			  case 0:
				(*parent)->bf = 1;
				*unbalanced   = FALSE;
				break;
			  case 1:
				left_rotation(parent, FALSE, unbalanced);
				break;
			}
        }
 	} 
    else 
    {
		/* Here deleteVal == (*parent)->value, so (*parent)
		 * is the address of the node we want to delete
		 */
		if((*parent)->left == NULL && (*parent)->right == NULL) 
        {	

			/* Kill a leaf node, easy
			 */
			if(static_local_destroy)
				deleteNode(*parent);

			*parent = NULL;
			*unbalanced = TRUE;

		} 
        else if((*parent)->left == NULL || (*parent)->right == NULL) 
        {

			/* Kill a node with only one child, easy
			 */
			AVLnode* child = *parent;

			*parent = ((*parent)->left == NULL) ?
				  (*parent)->right :
				  (*parent)->left;

			if(static_local_destroy)
				deleteNode(child);

			*unbalanced = TRUE;

	 	} 
        else 
        {
			/* Oh dear. This node has two children. Get
			 * the greatest value from the left subtree.
			 */
			AVLnode* gtChild = (*parent)->left;

			while(gtChild->right != NULL)
				gtChild = gtChild->right;
			
			/* Recurse to delete the (now duplicated) value from
			 * the subtree to the left of this node....
			 */
			static_local_destroy = FALSE;
			avl_delete(&(*parent)->left, gtChild->value, 
							unbalanced);
			static_local_destroy = TRUE;

			gtChild->bf    = (*parent)->bf;
			gtChild->left  = (*parent)->left;
			gtChild->right = (*parent)->right;
			deleteNode(*parent);
			*parent = gtChild;
	
			/* .... and rejig the BFs in the parent
			 */
			if(*unbalanced) 
            {		
				/* Left branch has become lower
				 */
				switch((*parent)->bf) 
                {
				  case 1:
					(*parent)->bf = 0;
					break;
				  case 0:
					(*parent)->bf = -1;
					*unbalanced = FALSE;
					break;
				  case -1:
					right_rotation(parent, FALSE,
								unbalanced);
					break;
				}
			}
		}
	}
} 

/* Use as height(root, 0); to determine the height of a tree
 */
int	height(AVLnode* start, int depth)
{
	int	heightLeft;
	int	heightRight;

	if(start == NULL)
		return depth;

	heightLeft = height(start->left, depth + 1);
	heightRight = height(start->right, depth + 1);

	return heightLeft > heightRight ? heightLeft : heightRight;
}

/* Show the tree as a tree, rather than inorder, postorder, or preorder
 */
void	showTree(AVLnode* root)
{
	AVLnode ** array;
	int	 	   depth;
	int		   i, j;
	int		   spaces;
	char       formatString[10], outputBuffer[30];

	/* All the left shifting below is to calculate powers of 2. These
	 * are (not surprisingly) very handy with binary trees.
	 */
	depth = height(root, 0);
	array = calloc( ((1 << depth) - 1), sizeof(AVLnode*));
	treeToArray(root, 1, array);

	/* For all of the nodes at each level in the tree ...
	 */
	for(i = 1; i <= depth; i++) 
    {

		spaces = 79 / ((1 << (i - 1)) + 1);
		sprintf(formatString, "%%%ds", spaces);
		for(j = (1 << (i - 1)); j < (1 << i); j++) {

			if(array[j - 1] == NULL) 
            {
				printf(formatString, "X");
			}
            else
            {
				sprintf(outputBuffer, "%d",
							array[j - 1]->value);

				printf(formatString, outputBuffer);
			}
		}
		printf("\n");
	}
	free(array);
}

/* Used by the above function
 */
void treeToArray(AVLnode* p, int  number, AVLnode* array[])
{
	if(p == NULL)
		return;

	array[number - 1] = p;
	treeToArray(p->left, number * 2, array);
	treeToArray(p->right, number * 2 + 1, array);
}

int main(void)
{
	int       v;
	int	      option;
	int       balance;
	AVLnode * root = NULL;
	
	for(;;)
	{
		printf("i)nsert d)elete q)uit  >> ");
		fflush(stdin);
		option = getchar();
		option = tolower(option);
		
		switch(option) 
        {
		  case '0': case '1': case '2':
		  case '3': case '4': case '5':
		  case '6': case '7': case '8':
		  case '9':
			/* Just typing an integer defaults to insert
			 */
			ungetc(option, stdin);
			option = 'n';
			/* FALL THROUGH */

		  case 'i':
		  case 'd':
			/* Suppress the prompt if the user has typed "i 77"
			 * or "d 89" etc
			 */
			if((option == 'i' || option == 'd')
						&& getchar() == '\n')
				printf("integer to %s  >> ",
					option == 'i' ? "insert" : "delete");
				
			scanf("%d", &v);
			if(option == 'i' || option == 'n')
				avl_insert(&root, v, &balance);
			else
				avl_delete(&root, v, &balance);
			break;
		  case 'q':
		  	exit(0);
			/*break*/
		  default:
			printf("unknown option '%c' (%d)\n", option, option);
			continue;
		}
		showTree(root);
		printf("\n");
	}

	return 0;
}
