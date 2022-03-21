/*********************************************************************
 *                                                                   
 *  Filename:     FUNCPTRS.C
 *  Directory:    POINTERS
 *
 *  Description:  This program uses a simple switch statement to   
 *                select a function to call. Replace the switch       
 *                statement with function-pointer logic.               
 *
 *********************************************************************/

#include <stdio.h>

void Command0(void);
void Command1(void);
void Command2(void);
void Command3(void);
void Command_Default(void);

int     main(void)
{
    int x;

    do
    {
        printf("Enter option in range 0-3:\n");
        fflush(stdin);
    } 
    while(scanf("%d", &x) != 1);
    
    switch(x)
    {
        case 0:    Command0();         break;
        case 1:    Command1();         break;
        case 2:    Command2();         break;
        case 3:    Command3();         break;
        default:   Command_Default();  break;
    }

    return 0;
}

void Command0(void)
{
    printf("This is command 0\n");
}

void Command1(void)
{
    printf("This is command 1\n");
}

void Command2(void)
{
    printf("This is command 2\n");
}

void Command3(void)
{
    printf("This is command 3\n");
}

void Command_Default(void)
{
    printf("!Error!\n");
}
