#include <stdio.h>
#include <stdlib.h>


int sqrd(int);

int main()
{
    int usernum = 0;
    int result = 0;

    printf("Enter a number: ");
    scanf("%d", &usernum);
    result = sqrd(usernum);
    printf("%d", result);
    return 0;
}

int sqrd(int n)
{
    return n*n;
}
