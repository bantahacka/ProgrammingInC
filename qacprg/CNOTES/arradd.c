/* arradd.c */

#include <stdio.h>

int addupintarr(int [], int);

int main(void)
{
        int numarray[5] = {1, 4, 9, 16, 25};
        int total = 0;

        total = addupintarr(numarray, 5);
        printf("Total is %d\n", total);

        return 0;
}


int addupintarr(int na[], int size)
{
        int i;
        int sum;

        for(i = 0, sum = 0; i < size; i++)
        {
                sum += na[i];
        }

        return sum;
}
