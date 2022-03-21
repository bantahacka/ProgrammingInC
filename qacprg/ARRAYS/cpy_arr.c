/************************************************************************
 *                                                                      *
 *   cpy_arr.c   Arrays - Qu. 2 Code Template                           *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototypes for print_array */
/* and copy_array             */

void print_array(int [], int);
void  copy_array(int [], int [], int);

int main(void)
{
    int a1[5] = {3, 5, -1, 7, 6};
    int a2[5] = {2, 2, 2, 2, 2};

    copy_array(a2, a1, 5);
    print_array(a2, 5);

    return 0;
}


/* borrowed from previous solution */

void print_array(int a[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\n");
}


/* Function copy_array here */

