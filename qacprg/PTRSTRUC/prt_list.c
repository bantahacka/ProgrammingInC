/************************************************************************
 *                                                                      *
 *   prt_list.c   Pointers/Structures - Qu. 4 (Optional) Code Template  *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct Node
{
    struct  Node *next; /* next link in list */
    int i_val;          /* value stored at this node*/
};

struct Node n1 = { NULL, 40 };
struct Node n2 = { &n1,  32 };
struct Node n3 = { &n2,  8  };
struct Node n4 = { &n3,  -2 };

struct Node *head_of_list = &n4;

void print_list(struct Node *);

int main(void)
{
    print_list(head_of_list);

    /*  Could have written:
     *
     *   print_list(&n4);
     */

     return 0;
}

void print_list(struct Node *first_node)
{
    /* YOUR CODE HERE PLEASE */
}



