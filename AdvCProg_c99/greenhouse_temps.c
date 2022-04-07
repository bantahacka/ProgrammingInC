#include <stdio.h>
#include <stdlib.h>
#define DAYS_IN_WEEK 7

typedef struct //temp_date <--Optional
{
    int record_day;
    float temperature;
} temp_date;

void data_fill(temp_date[]); // Populate temps
void zero_it(temp_date[]); // Zero the temps
void display_temps(temp_date[]); // Display the temps

int main()
{
    //struct temp_date temp_records[DAYS_IN_WEEK]; <--Only required if we have temp_date declared in the above struct declaration
    temp_date temp_records[DAYS_IN_WEEK];
    zero_it(temp_records);
    data_fill(temp_records);
    display_temps(temp_records);
    return 0;
}

void zero_it(temp_date date[])
{
    int i;
    for (i=0;i<DAYS_IN_WEEK;i++)
    {
        date[i].record_day = i+1;
        date[i].temperature = 0;
    }

}

void data_fill(temp_date date[])
{
    int i;
    for (i=0;i<DAYS_IN_WEEK;i++)
    {
        printf("Day %d of %d\n", date[i].record_day, DAYS_IN_WEEK);
        puts("Enter temp in degress C: ");
        scanf("%f", &date[i].temperature);
    }
}

void display_temps(temp_date date[])
{
    int i;
    for (i=0;i<DAYS_IN_WEEK;i++)
    {
        printf("Day %d of %d: %.2f\n", date[i].record_day, DAYS_IN_WEEK, date[i].temperature);
    }
}
