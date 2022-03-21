/************************************************************************
 *                                                                      *
 *   prt_arr.c Arrays - Qu. 1 Model Solution                            *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Prototype for print_array. The first parameter is an array of ints, */
/* and the second parameter is int.                                    */

void print_array(int [], int);

/* Does this look cryptic? Remember that we could have written it with */
/* identifiers, like this:                                             */
/*                                                                     */
/*   void print_array(int arr[], int size);                            */ 
/*                                                                     */
/* The form we have used above (without identifiers) is the verbose    */
/* with identifiers removed.                                           */
/*                                                                     */

int main(void)
{
    int my_array[5] = { 7, 6, 5, 4, 3 };
    int other[7] = { 2, 4, 6, 8, 10, 12, 14 };

    print_array(my_array, 5);
    print_array(other, 7);

    return 0;
}   

void print_array(int a[], int size)
{
    int i;
    for(i = 0; i < size; i++)
        printf("%d ", a[i]);

    printf("\n");
}
