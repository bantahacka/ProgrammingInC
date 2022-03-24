#include <stdio.h>
#include <stdlib.h>

int main()
{
    // How many ints do we want?
    int size;
    puts("How many elements? ");
    scanf("%d", &size);

    // Create pointer for start of heap block
    int *ptr_mydata;

    // Try to find contiguous block on the heap for requested size
    ptr_mydata = malloc(size * sizeof(int));

    // MANDATORY - Do we get any memory?
    if(ptr_mydata != NULL)
    {
        puts("\nHeap allocated");
        int *ptr_tmp;
        ptr_tmp = ptr_mydata;
        *ptr_tmp = 99;
        printf("\n%d", *ptr_tmp);
        // Finished with the memory so free it to stop memory leaks
        free(ptr_mydata);
    }
    else
    {
        puts("\nInsufficient memory on the heap!");
    }

    return 0;
}
