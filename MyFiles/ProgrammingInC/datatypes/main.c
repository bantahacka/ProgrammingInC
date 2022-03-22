#include <stdio.h>
#include <stdlib.h>

int main()
{
    /* char */
    char initial = 'A';
    int letter = 65;
    float accpi = 3.14f;

    /* explicit typecasting */
    char newchar = (char)letter;
    int roughpi = (int)accpi;

    printf("%c\n", initial);
    /* Expect to see the letter A as 65 */
    printf("%d\n", initial);

    /* Expect to see number 65 as the letter A */
    printf("%c\n", letter);

    printf("%c\n", newchar);

    printf("%d\n", roughpi);


    return 0;
}
