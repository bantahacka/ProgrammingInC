// Declarationts
#include <stdlib.h>
#include <stdio.h>

int sum_it(const int *, size_t);

int main()
{
    int (*f_ptr)(const int *, size_t); //ptr to a function that takes a const int ptr and size_t, and the function returns an int
    f_ptr = &sum_it; // Initialise pointer. Give memory address of function sum_it to f_ptr pointer. Function names degrade to memory address so do not need to use &
    const int data[] = {1,2,3,4,5};
    size_t n = sizeof(data)/sizeof(data[0]);
    //int result = sum_it(data, n);
    int result = f_ptr(data, n);
    printf("Total: %d", result);
    return 0;
}

int sum_it(const int *data_to_sum, size_t size)
{
    int i;
    int sum_result=0;
    for (i=0;i<size;i++)
    {
        sum_result += data_to_sum[i];
    }
    return sum_result;
}