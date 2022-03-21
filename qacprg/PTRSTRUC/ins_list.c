/************************************************************************
 *                                                                      *
 *   ins_list.c   Pointers/Structures - Qu. 5 (Optional) Code Template  *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct Node
{
    struct  Node *next; /* next link in list */
    int i_val;          /* value stored at this node*/
};


/* Statically defined linked list */

struct Node n1 = { NULL, 40 };
struct Node n2 = { &n1,  32 };
struct Node n3 = { &n2,  8  };
struct Node n4 = { &n3,  -2 };

struct Node *head_of_list = &n4;

/* NEW nodes to add to the list - see main() */

struct Node new_node    = { NULL, 23 };
struct Node new_first   = { NULL, -20 };
struct Node new_last    = { NULL, 100 };

void print_list(struct Node *);
struct Node* insert_node(struct Node *, struct Node *);

int main(void)
{
    printf("TEST 1 (Add 23 to the middle of list): ");
    head_of_list = insert_node(head_of_list, &new_node);
    print_list(head_of_list);

    printf("TEST 2 (Add -20 to begining of list) : ");
    head_of_list = insert_node(head_of_list, &new_first);
    print_list(head_of_list);

    printf("TEST 3 (Add 100 to the end of list)  : ");
    head_of_list = insert_node(head_of_list, &new_last);
    print_list(head_of_list);

    return 0;
}



struct Node*    insert_node(struct Node *node, struct Node *new)
{
    /* INSERT CODE */
}


void    print_list(struct Node *node)
{
    /* SOLUTION CODE FROM QUESTION 4 */
    for(; node != NULL; node = node->next)
        printf("%d, ", node->i_val);
    printf("\b\b \n\n");    /* get rid of last , */
}

