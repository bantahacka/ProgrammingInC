#include <stdio.h>
#include <stdlib.h>
/* Will not work as we are passing by value, not reference
void swap(int, int);

int main()
{
    int a = 10;
    int b = 20;
    printf("Before: a is %d and b is %d",a, b);
    swap(a,b); // Pass by value
    printf("\nAfter: a is %d and b is %d",a, b);
    return 0;
}

void swap(int n1, int n2)
{
    int temp;
    temp = n1;
    n1 = n2;
    n2 = temp;
}
*/

void swap(int *, int *);

int main()
{
    int a = 10;
    int b = 20;

    int *ptr_a = &a;
    int *ptr_b = &b;

    printf("Before: a is %d and b is %d",a, b);
    swap(ptr_a,ptr_b); // Pass by reference
    /*swap(&a,&b);*/ //This also works if you don't use *ptr_a and *ptr_b above.
    printf("\nAfter: a is %d and b is %d",a, b);
    return 0;
}

void swap(int *ptr_n1, int *ptr_n2)
{
    int temp;
    temp = *ptr_n1;
    *ptr_n1 = *ptr_n2;
    *ptr_n2 = temp;
}
