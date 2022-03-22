#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main()
{
    const unsigned int RESULT_LIMS[4] = {39, 64, 80, 100};
    const unsigned int INPUT_LIMS[2] = {0, 100};
    char result_word[12];
    unsigned int result1 = 101;
    unsigned int result2 = 101;
    unsigned int result3 = 101;
    float avg_result = 0;


    printf("For each exam, enter the students result:");
    while(result1 < INPUT_LIMS[0] || result1 > INPUT_LIMS[1])
    {
        printf("\nEnter the result for exam 1: ");
        scanf("%u", &result1);
    }
    while(result2 < INPUT_LIMS[0] || result1 > INPUT_LIMS[1])
    {
        printf("\nEnter the result for exam 2: ");
        scanf("%u", &result2);
    }
    while(result3 < INPUT_LIMS[0] || result1 > INPUT_LIMS[1])
    {
        printf("\nEnter the result for exam 3: ");
        scanf("%u", &result3);
    }

    avg_result = (result1+result2+result3)/3;

    if(avg_result <= RESULT_LIMS[0])
    {
        strcpy(result_word, "Fail");
    }
    else
    {
        if (avg_result <= RESULT_LIMS[1])
        {
            strcpy(result_word, "Pass");
        }
        else
        {
            if (avg_result <= RESULT_LIMS[2])
            {
                strcpy(result_word, "Merit");
            }
            else
            {
                strcpy(result_word, "Distinction");
            }
        }
    }

    printf("\nStudent achieved an average mark of %.2f which is a %s.", avg_result, result_word);

    return 0;
}
