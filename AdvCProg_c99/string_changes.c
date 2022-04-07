#include <stdio.h>

void change(void);

int main() {
    change(); // Prints lowercase hello
    change(); // Crashes program :(
    return 0;
}

void change(void)
{
    char * str = "hello";

    printf("%s\n", str);
    *str = 'H';
}
