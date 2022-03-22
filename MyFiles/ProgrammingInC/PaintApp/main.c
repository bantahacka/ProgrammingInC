#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    float r_width, r_length, r_height, r_area, tin_coverage, cost_of_tin, total_cost = 0;
    unsigned int total_tins = 0;

    /* Ask user for width, length and height of room */
    puts("Enter the width of the room in m (max 2 decimals): ");
    scanf("%f", &r_width);
    puts("Enter the length of the room in m (max 2 decimals): ");
    scanf("%f", &r_length);
    puts("Enter the height of the room in m (max 2 decimals): ");
    scanf("%f", &r_height);

    /* Ask for area coverage per tin */
    puts("Enter the area covered by a single tin in m2: ");
    scanf("%f", &tin_coverage);

    /* Ask for cost of tin */
    puts("Enter the cost of a tin in GBP: ");
    scanf("%f", &cost_of_tin);

    /* Calculate areas */
    r_area = ((2 * r_width) * r_height) + ((2 * r_length) * r_height);
    total_tins = ceil(r_area / tin_coverage);
    total_cost = total_tins * cost_of_tin;
    printf("You need %d tins at a cost of %.2f to cover this room.", total_tins, total_cost);

    return 0;
}
