#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n[] = {10, 20, 30, 40, 50};
    int *ptr_n = &n;

    printf("Value of 0: %d\n", n[0]);
    printf("Value of 0 via ptr: %d\n", *ptr_n);

    for (int i = 0;i < (sizeof(n)/sizeof(n[0])); i++)
    {
        // Print out dereferenced ptr, then increment ptr by 1 address space.
        printf("\n%d", *ptr_n);
        *ptr_n++;
    }
    return 0;
}
