#include <stdlib.h>
#include <stdio.h>

// Creation of linked list node
struct node
{
    int data; // data
    struct node *next; // pointer ot next node
};

typedef struct node node_t; // Creating the node type

void print_list(node_t *);
void print_listr(node_t *);

int main()
{
    // Create 1st node
    node_t *ptr_head = malloc(1 * sizeof(node_t));
    (*ptr_head).data = 69;
    (*ptr_head).next = NULL;

    // Create 2nd node
    node_t *ptr_new = malloc(1 * sizeof(node_t));
    ptr_new->data = 420;
    ptr_new->next = NULL;

    // Link head to first
    ptr_head->next = ptr_new;
    print_list(ptr_head);

    return 0;
}

void print_list(node_t *p)
{
    while(p)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

void print_listr(node_t *p)
{
    // Recursively print backwards
    if(p)
    {
        print_listr(p->next);
        printf("%d\n", p->data);
    }
}