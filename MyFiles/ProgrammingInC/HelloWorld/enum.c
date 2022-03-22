#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    enum season {spring, summer, autumn, winter};

    printf("%d\n", spring);
    printf("%d\n", summer);
    printf("%d\n", autumn);
    printf("%d\n", winter);

    enum season fall = 2;
    enum season discontent = winter;

    printf("%d\n", spring);
    printf("%d\n", summer);
    printf("%d\n", autumn);
    printf("%d\n", winter);
    printf("%d\n", fall);
    printf("%d\n", discontent);

}
