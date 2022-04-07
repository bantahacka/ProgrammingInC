#include <stdlib.h>
#include <stdio.h>

int main()
{
    int no_of_readings;
    int no_of_days;
    printf("Enter the number of readings being taken per day: ");
    scanf("%d", &no_of_readings);
    printf("\nEnter the number of days you want to take readings for: ");
    scanf("%d", &no_of_days);

    float (*array)[no_of_readings] = calloc(no_of_days, no_of_readings * sizeof(float));
    if(array)
    {
        printf("\nEnter the first reading on day one: ");
        scanf("%f", &array[0][0]);
        printf("%.2f", array[0][0]);
    }
    else
    {
        printf("Mem err");
        free (array);
        return -1;
    }
    free (array);
    return 0;
}