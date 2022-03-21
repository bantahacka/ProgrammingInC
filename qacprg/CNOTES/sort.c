/* Advanced Language Topics - Pointers to Functions Example */

#include <stdio.h>

int larger(int, int);
int smaller (int, int);
int sort ( int (*) ( int, int ), int, int);

int main(void)
{
    int x = 5, y = 7, result;
    result = sort (larger, x, y);
    printf ("larger = %d\n", result);
    result = sort (smaller, x, y);
    printf ("smaller = %d\n", result);

    return 0;
}

int sort (int (*func) (int, int), int a, int b)
{
    return ((*func) (a, b));
}

int larger (int num1, int num2)
{
    return (num1 > num2) ? num1 : num2;
}

int smaller (int num1, int num2)
{
    return (num1 < num2) ? num1 : num2;
}
