/*********************************************************************
 *                                                                   
 *  Filename:     RPNCALC.C
 *  Directory:    MODULAR\SOLUTION
 *
 *  Description:  Simplified RPN calculator.
 *
 *********************************************************************/

#include <stdio.h>
#include "dstack.h"


typedef struct
{
   enum { NUMBER, PLUS, MINUS, TIMES, DIVIDE, STOP }  type;
   double number;
}  ITEM;
             
             
void GetItem (ITEM *);
             
             
int main(void)
{
    ITEM   x;
    double d1, d2;

    printf("Enter an RPN expression terminated by \'.\'\n");

    StackInit();

    for (GetItem(&x); x.type != STOP; GetItem(&x))
    {        
        switch (x.type)
        {
        case PLUS:
            d1 = StackPop();
            d2 = StackPop();
            StackPush(d2+d1);
            break;

        case MINUS:
            d1 = StackPop();
            d2 = StackPop();
            StackPush(d2-d1);
            break;

        case TIMES:
            d1 = StackPop();
            d2 = StackPop();
            StackPush(d2*d1);
            break;

        case DIVIDE:
            d1 = StackPop();
            d2 = StackPop();
            StackPush(d2/d1);
            break;

        case NUMBER:
            StackPush(x.number);
            break;
        }
    }

    d1 = StackPop();

    printf("Answer is %f\n", d1);

    return 0;
}


void GetItem (ITEM * pThing)
{
    int ch;

    while ( (ch=getchar()) == ' ' || ch=='\t' || ch=='\n' || ch=='\r')
        ;  /* Skip white spaces */

    switch (ch)
    {
    case '.':
        pThing->type = STOP;
        break;


    case '+':
        pThing->type = PLUS;
        break;


    case '-':
        pThing->type = MINUS;
        break;


    case '*':
        pThing->type = TIMES;
        break;


    case '/':
        pThing->type = DIVIDE;
        break;


    case '0': case '1' : case '2': case '3': case '4':
    case '5': case '6' : case '7': case '8': case '9':

        ungetc(ch, stdin);

        if (1 == scanf("%lf", &pThing->number))
            pThing->type = NUMBER;
        else
            printf("Cannot read number...\n");
        break;


    default:
        printf("Unrecognised symbol...\n");
        break;
    }
}


