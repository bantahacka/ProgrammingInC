/*********************************************************************
 *                                                                   
 *  Filename:     FUNCPTRS.C
 *  Directory:    POINTERS\SOLUTION
 *
 *  Description:  This program uses an array of function pointers 
 *                to select a function to call.
 *
 *********************************************************************/

#include <stdio.h>

void Command0(void);
void Command1(void);
void Command2(void);
void Command3(void);
void Command_Default(void);

/* 
 * Create a typedef for pointer to void/void function. This
 * simplifies the syntax later 
 */

typedef void (*PVV)(void);

int     main(void)
{
    /* Create a table holding the function addresses */
    PVV Table[] = { Command0, Command1, Command2, Command3 };

    PVV pf;   /* Declare a pointer to a function of the appropriate type */

    int x;

    do
    {
        printf("Enter option in range 0-3:\n");
        fflush(stdin);
    } 
    while(scanf("%d", &x) != 1);
    
    if(x >= 0 && x <= 3)
    {
        pf = Table[x];
    }
    else
    {    
        pf = Command_Default;
    }

    (*pf)();        /* Call the appropriate function indirectly   */
                    /* Could also have called as follows:  pf();  */

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
