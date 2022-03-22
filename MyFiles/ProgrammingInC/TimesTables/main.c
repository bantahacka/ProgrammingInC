#include <stdio.h>
#include <stdlib.h>


int main()
{
    const int MIN_TBL = 1;
    const int MAX_TBL = 12;
    const int MIN_ROWS = 1;
    const int MAX_ROWS = 50;
    unsigned int usr_tbl = 0;
    unsigned int usr_rows = 0;
    unsigned int i;
    unsigned int mult_res = 0;

    printf("Welcome to the Times Tables program!");
    printf("\nEnter the times table you want to use between %d and %d: ", MIN_TBL, MAX_TBL);
    scanf("%d", &usr_tbl);
    while(usr_tbl < MIN_TBL || usr_tbl > MAX_TBL)
    {
        printf("\nInvalid number.");
        printf("\nEnter the times table you want to use between %d and %d: ", MIN_TBL, MAX_TBL);
        scanf("%u", &usr_tbl);
    }

    printf("\nEnter the number of rows you want to view between %d and %d: ", MIN_ROWS, MAX_ROWS);
    scanf("%u", &usr_rows);
    while(usr_rows < MIN_ROWS || usr_rows > MAX_ROWS)
    {
        printf("\nInvalid number.");
        printf("\nEnter the number of rows you want to view between %d and %d: ", MIN_ROWS, MAX_ROWS);
        scanf("%u", &usr_rows);
    }

    for (i=0;i<=usr_rows;i++)
    {
        mult_res = i * usr_tbl;
        printf("\n%3u x%3u = %3u", i, usr_tbl, mult_res);
    }
    return 0;
}
