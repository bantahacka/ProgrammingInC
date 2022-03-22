#include <stdio.h>
#include <stdlib.h>

int main()
{
    int data[4];

    data[0] = 10;
    data[1] = 20;
    data[2] = 30;
    //data[3] = 40;
    data[6] = 222;

    printf("%d\n", data[2]);
    // data[3] will return 0, or garbage
    printf("%d\n", data[3]);
    // This will also return 0 or garbage
    printf("%d\n", data[-10]);
    // Print the value and address of data[0] and data[1].
    printf("%d\n", data[0]);
    printf("%x\n", &data[0]);
    printf("%d\n", data[1]);
    printf("%x\n", &data[1]);

    // Looping through
    for (int i=0; i<20; i++)
    {
        printf("%d in %x\n", data[i], &data[i]);
    }
    return 0;
}
