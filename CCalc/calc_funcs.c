#include "header_includes.h"
void printhelp()
{
    printf("\nHelp\n____\n\n--help - Show this help menu\n--start - Start the calculator\n\n");
}

void printmenu()
{
    printf("\nWelcome to the C Calculator! Choose an option from the list below.\n\n"
           "[1] Addition.\n"
           "[2] Subtraction.\n"
           "[3] Multiplication.\n"
           "[4] Division.\n"
           "[5] Percentage Calculator.\n"
           "[6] Power.\n"
           "[7] Square Root.\n"
           "[8] Cube Root.\n"
           "[9] Add last result to memory.\n"
           "[10] Display number in memory.\n"
           "[11] Clear memory.\n"
           "[12] Exit calculator.\n\n"
           "Enter an option: ");
}

float entersingle()
{
    float num1;
    printf("\nEnter a number: ");
    scanf("%f", &num1);
    return num1;
}

float enterfirst()
{
    float num1;
    printf("\nEnter the first number: ");
    scanf("%f", &num1);
    return num1;
}

float entersecond()
{
    float num2;
    printf("\nEnter the second number: ");
    scanf("%f", &num2);
    return num2;
}

float enterpwr()
{
    float num1;
    printf("\nEnter the power: ");
    scanf("%f", &num1);
    return num1;
}

void addition(float num1, float num2, float *ans)
{
    *ans = num1 + num2;
}

void subtraction(float num1, float num2, float *ans)
{
    *ans = num1 - num2;
}

void multiplier(float num1, float num2, float *ans)
{
    *ans = num1 * num2;
}

void divider(float num1, float num2, float *ans)
{
    *ans = num1 / num2;
}

void pct(float num1, float num2, float *ans)
{
    *ans = (num1/num2) * 100;
}

void topower(float num1, float num2, float *ans)
{
    *ans = powf(num1, num2);
}

void sqroot(float num1, float *ans)
{
    *ans = sqrtf(num1);
}

void curt(float num1, float *ans)
{
    *ans = cbrtf(num1);
}

void add_to_mem(float *num1, float *memvar)
{
    *memvar = 0.00;
    *memvar = *num1;
}

void ret_from_mem(float *ans, float *memvar)
{
    *ans = 0.00;
    *ans = *memvar;
}

void mem_clear(float *memvar)
{
    *memvar = 0.00;
}

