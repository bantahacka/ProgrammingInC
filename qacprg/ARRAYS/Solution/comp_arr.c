/************************************************************************
 *                                                                      *
 *   comp_arr.c   Arrays - Qu. 5 (Optional) Model Solution              *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int comp_array(int [], int[], int);

int main(void)
{
    int a1[6] = {2, 2, 2, 2, 3, 4};
    int a2[6] = {2, 2, 2, 7, 8, 9};

    int match = comp_array(a1, a2, 6);

    if (match != -1)
    {
        printf("Arrays differ first at element %d\n", match);
    }
    else
    {
        printf("Arrays are identical\n");
    }

    return 0;
}

int comp_array(int array1[], int array2[], int size)
{
    int i;

    for(i = 0; array1[i] == array2[i] && i < size; i++)
        ; /* do nothing */

    return (i != size)? i : -1 ;
}


