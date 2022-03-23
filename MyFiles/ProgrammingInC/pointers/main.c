#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    n = 10;

    // Create a pointer (Wild ptr = unassigned)
    // Pointer to an integer
    int *ptr_n;

    // Assign the address of n to ptr_n
    ptr_n = &n;



    printf("Value of n is %d", n);
    printf("\nAddress of n is %x", &n);
    // Show value of ptr_n to prove it is the address
    printf("\nValue of ptr_n is %x", ptr_n);
    // Dereference to get n via the ptr
    printf("\nValue of n (Via ptr) is %d", *ptr_n);


    return 0;
}
