#include <stdio.h>
#include <stdlib.h>

int comparitor(const void *, const void *);
int comparitor_f(const void *, const void *);

int main()
{
    // Unsorted data
    int values[] = {10,30,20,15,45};
    puts("Values before sorting...\n");
    for (int i=0;i<5;i++)
    {
        printf("%d ", values[i]);
    }

    // Sort the data
    // qsort takes the following: address of array to sort, no. of elements in array, size of each element in array, comparitor
    qsort(values, 5, sizeof(int), comparitor);

    // Sorted data
    puts("\n\nValues after sorting...\n");
    for (int i=0;i<5;i++)
    {
        printf("%d ", values[i]);
    }

    // Unsorted data
    float values_f[] = {10.50,30.21,20.65,45.13,15.34};
    puts("Values before sorting..\n");
    for (int i=0;i<5;i++)
    {
        printf("%.2f ", values_f[i]);
    }

    // Sort the data
    // qsort takes the following: address of array to sort, no. of elements in array, size of each element in array, comparitor
    qsort(values_f, 5, sizeof(float), comparitor_f);

    // Sorted data
    puts("\n\nValues after sorting...\n");
    for (int i=0;i<5;i++)
    {
        printf("%.2f ", values_f[i]);
    }

    return 0;
}

int comparitor(const void *first, const void *second)
{
    return (*(int*)first - *(int*)second);
}

int comparitor_f(const void *first, const void *second)
{
    return (int)(*(float*)first - *(float*)second);
}