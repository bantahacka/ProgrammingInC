/* Data Types, Variables and Constants - Type char an example */
#include <stdio.h>

int main (void)
{       
    char letter_a; 
    char nl;

    letter_a = 'a';
    nl = '\n';

    printf("Letter value of a %c\n", letter_a);
    printf("Letter value of next char %c\n", letter_a + 1);
    printf("Integer value of a %d\n", letter_a);
    printf("Next %cline \n", nl);

    return 0;
}
