#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int d_roll;
    time_t t;
    srand((unsigned) time(&t));
    do
    {
        d_roll = rand() % 6 + 1;
        printf("\nRoll: %d", d_roll);
        if (d_roll == 6)
        {
            puts("\nYou rolled a 6!");
            break;
        }
        else
        {
            continue;
        }
    }
    while(d_roll != 6);

    return 0;
}
