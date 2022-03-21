/************************************************************************
 *                                                                      *
 *   swap_arr.c   Arrays - Qu. 6 (Optional) Model Solution              *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

void print_array(int [], int);           /* Borrowed from qu. 1 */
void copy_array(int [], int [], int);    /* Borrowed from qu. 2 */
int comp_array(int [], int [], int);     /* Borrowed from qu. 5 */
int swap_array(int [], int[], int);

int main(void)
{
    int a1[6] = {2, 2, 2, 2, 3, 4};
    int a2[6] = {2, 2, 2, 7, 8, 9};


    int swapped = swap_array(a1, a2, 6);        /* a1 <---> a2      */

    if (swapped)
    {
        printf("Arrays are successfully swapped\n");
        printf("i.e. a1 is "); print_array(a1, 6);
        printf("and  a2 is "); print_array(a2, 6);
    }
    else
    {
        printf("No need to swap, the arrays are identical\n");
    }

    return 0;
}


/*********************PROVIDED**********************/

void print_array(int a[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\n");
}


/*********************PROVIDED**********************/

void copy_array(int d[], int s[], int size)
{
    int i;

    for(i = 0; i < size; i++)
        d[i] = s[i];
}


/*********************PROVIDED**********************/

int comp_array(int array1[], int array2[], int size)
{
    int i;

    for(i = 0; array1[i] == array2[i] && i < size; i++)
        ; /* do nothing */

    return (i != size)? i : -1 ;
}


int swap_array(int array1[], int array2[], int size)
{
    int i;
    int temp;

    if (comp_array(array1, array2, size) != -1)   /* not the same */
    {
        for (i = 0, temp = 0 ; i < size ; i++)
        {
            temp = array1[i];
            array1[i] = array2[i];
            array2[i] = temp;
        }
        return 1;
    }
    return 0;                               /* they were the same */
}


