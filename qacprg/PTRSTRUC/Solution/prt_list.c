/************************************************************************
 *                                                                      *
 *   prt_list.c   Pointers/Structures - Qu. 4 (Optional) Model Solution *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct Node
{
    struct  Node *next;     /* next link in list         */
    int          i_val;     /* value stored at this node */
};

/* Statically defined linked list */

struct Node n1 = { NULL, 40 };
struct Node n2 = { &n1,  32 };
struct Node n3 = { &n2,  8  };
struct Node n4 = { &n3,  -2 };

struct Node *head_of_list = &n4;


void print_list(struct Node *);
void reverse_print(struct Node *);


int main(void)
{
    printf("\nList is: ");
    print_list(head_of_list);
    
    printf("\nIn reverse: ");
    reverse_print(head_of_list);
    printf("\n");

    return 0;
}

void print_list(struct Node *node)
{
    for(; node != NULL; node = node->next)
        printf("%d, ", node->i_val);
    printf("\b\b \n\n");    /* get rid of last , */
}

void reverse_print(struct Node *node)
{
    if (node != NULL)
    {
        reverse_print(node->next);
        printf("%d, ",node->i_val);
    }
}


