#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

long add_up_int_array(int [], size_t);

int main()
{
    int squares[] = {1, 4, 9, 16, 25, 36, 49, 64, 81, 100, 121, 144};
    long total = 0;
    total = add_up_int_array(squares, sizeof(squares)/sizeof(squares[0]));
    printf("Total is %ld\n", total);
    return 0;
}

long add_up_int_array(int a[], size_t size)
{
    long int_sum = 0;
    for(size_t i=0; i < size; i++)
    {
        int_sum += a[i];
    }
    return int_sum;
}
