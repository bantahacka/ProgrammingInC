#include <stdio.h>
#include <stdlib.h>

void change(double []);

int main()
{
    double vector[]  = {0.0,1.1,2.2,3.3,4.4};
    printf("\nOutside vector %x", vector);
    change(vector);
    printf("\n%f %f", vector[0],vector[3]);
    return 0;
    /*int data[4];

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
        // If out of range, other memory locations will be printed!
        printf("%d in %x\n", data[i], &data[i]);
    }
    return 0;*/

}

void change(double da[])
{
    da[0] = 3.14;
    da[3] = da[2] + da[4];
    printf("\n%x Inside function", da);
}
