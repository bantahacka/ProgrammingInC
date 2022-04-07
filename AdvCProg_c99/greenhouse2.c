#include <stdio.h>
#include <stdlib.h>
#ifndef MAX
#define MAX 10
#endif

void data_fill(float [][4]);
void print_day(int, float[][4]);
char *headings[] = {"Day", "Temperature"};
int exit_flag = 0;
int main()
{

    float temps[2][4];
    int user_day;
    data_fill(temps);
    while(exit_flag == 0)
    {
        printf("\nEnter a day to view: ");
        scanf("%d", &user_day);
        print_day(user_day, temps);
    }
    // Code to print all days
    /*float (*arrval)[4] = &temps[0];
    float (*end)[4] = &temps[2];
    printf("\n%*s | %*s", -2, headings[0], -MAX, headings[1]);
    for(int i=1;arrval < end;arrval++,i++)
    {
        float *val = *arrval;
        for(int j=0;j<4;j++)
        {
            printf("\n%-3d | %-10.2f", i, val[j]);

        }
    }*/
    return 0;
}

void data_fill(float (*p)[4])
{
    int i;
    int j;
    float user_input;
    for(i=0;i<2;i++)
    {
        for (j=0;j<4;j++)
        {
            printf("\nEnter temperature %d for day %d: ", i+1,j+1);
            scanf("%f", &user_input);
            p[i][j] = user_input;
        }
    }
}

void print_day(int user_day, float(*p)[4])
{
    int i;
    float (*start)[4] = &p[user_day-1];
    printf("\n%*s | %*s", -2, headings[0], -MAX, headings[1]);
    for (i=0;i<4;i++)
    {
        float *val = *start;
        printf("\n%-3d | %-10.2f", user_day, val[i]);
    }
    printf("\n");
}
