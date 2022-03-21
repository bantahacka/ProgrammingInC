/************************************************************************
 *                                                                      *
 *   cpy_arr.c Arrays - Qu. 2 Model Solution                            *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototypes */

void copy_array(int [], int[], int);
void print_array(int [], int);

int main(void)
{
    int a1[5] = {3, 5, -1, 7, 6};
    int a2[5] = {2, 2, 2, 2, 2};

    copy_array(a2, a1, 5);
    print_array(a2, 5);

    return 0;
}

void copy_array(int d[], int s[], int size)
{
    int i;

    for(i = 0; i < size; i++)
        d[i] = s[i];

    /* A more efficient solution is: 
     *
     *      while(--size >= 0)
     *          d[size] = s[size];
     */
}

void print_array(int a[], int size)
{
    int i;

    for(i = 0; i < size; i++)
        printf("%d\n", a[i]);
}
