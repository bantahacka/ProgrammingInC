#include <stdlib.h>
#include <stdio.h>

void q(void)
{
    printf("Goodbye World\n");
}

void p(void)
{
    printf("Hello World\n");
}

int main(void)
{
    void (*p)(void) = q;
    p(); // Runs function q
    return 0;
}