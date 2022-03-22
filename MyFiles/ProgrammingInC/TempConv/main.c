#include <stdio.h>
#include <stdlib.h>

/*float celToFar(float);
float farToCel(float);*/
float tempConv(int, float);

int main()
{
    int option = 0;
    float usertemp = 0;
    float result = 0;
    printf("Press 1 to convert from celcius to farenheit, or 2 to convert from farehneit to celcius: ");
    scanf("%d", &option);
    printf("\nEnter the temperature: ");
    scanf("%f", &usertemp);
    /*if(option == 1)
    {
        result = celToFar(usertemp);
        printf("%.2f Celcius in Farenheit is %.2f", usertemp, result);
    }
    else if(option == 2)
    {
        result = farToCel(usertemp);
        printf("%.2f Farenheit in Celcius is %.2f", usertemp, result);
    }
    */
    result = tempConv(option, usertemp);
    if (option == 1)
    {
        printf("%.2f Celcius in Farenheit is %.2f", usertemp, result);
    }
    else if (option == 2)
    {
        printf("%.2f Farenheit in Celcius is %.2f", usertemp, result);
    }
    return 0;
}

/*float celToFar(float cel)
{
    return (cel * 1.8) + 32;
}

float farToCel(float far)
{
    return (far - 32)/1.8;
}*/

float tempConv(int o, float temp)
{
    float rettemp = 0;
    if(o == 1)
    {
        rettemp = (temp * 1.8) + 32;
    }
    else
    {
        rettemp = (temp - 32)/1.8;
    }
    return rettemp;
}
