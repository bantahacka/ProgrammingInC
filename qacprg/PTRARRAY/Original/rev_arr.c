/************************************************************************
 *                                                                      *
 *   rev_arr.c   Pointers and Arrays - Qu. 7 (Optional) Code Template   *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#define SIZE 6

int  comp_array(int *, int *, int);     /*              */
void print_array(int *, int);           /* ALL PROVIDED */
void copy_array(int *, int *, int);     /*              */

/* PROTOTYPE for rev_array() here */

int main(void)
{
    int a1[SIZE] = {2, 2, 2, 2, 3, 4};
    int a2[SIZE] = {9, 8, 7, 7, 8, 9};

    int reverse = rev_array(a1, SIZE);

    if (reverse)
    {
        printf("Array successfully reversed and is now ");
        print_array(a1, SIZE);
    }
    else
    {
        printf("Array is palindromic\n");
    }

    return 0;
}


/*********************PROVIDED**********************/

void print_array(int *a, int size)
{
    int * end = a + size;
    while(a < end)
    {
        printf("%d ", *a++);
    }
    printf("\n");
}


/*********************PROVIDED**********************/

void copy_array(int *d, int *s, int size)
{
    int *end = s + size;

    while( s < end)
    {
        *d++ = *s++;
    }
}


/*********************PROVIDED**********************/

int comp_array(int *array1, int *array2, int size)
{
    int *start = array1 ;
    int *end = array1 + size;


    while (*array1 == *array2 && array1 < end)
    {
        array1++;
        array2++;
    }

    return (array1 != end)? array1 - start + 1 : 0 ;
}


/* Definition of rev_array() here, please ! */

