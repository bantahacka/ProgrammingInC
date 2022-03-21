/*********************************************************************
 *                                                                   
 *  Filename:     MENU.C
 *  Directory:    POINTERS\SOLUTION
 *
 *  Description:  This program uses function pointers to implement a 
 *                simple menu system. Each item in the menu is 
 *                represented by a MENUITEM structure, which holds
 *                the prompt string for the menu item and the associated
 *                function to call when this item is selected.
 *
 *********************************************************************/

#include <stdio.h>

void PrintHello(void);       /* Define some simple "action functions" */
void PrintBye(void);


typedef struct               /* Structure represents a single menu item */
{                      
    char  *text;             /* Textual prompt for this menu item   */
    void (*pfunc)(void);     /* Function to call for this menu item */
} MENUITEM;


MENUITEM theMenuItems[] =    /* Array of menu items (ended by NULL string) */
{
    { "Say hello",    PrintHello },
    { "Say goodbye",  PrintBye },
    { NULL, NULL }
};


void Menu(MENUITEM items[]);  /* Function to display menu and select item */

int     main(void)
{
    Menu(theMenuItems);

    return 0;
}


void Menu (MENUITEM items[])
{
    int num;    /* Number of items in menu */
    int sel;    /* Item selected by user   */

    for (num = 0; items[num].text != NULL; num++)
    {    
        printf("%2d : %s\n", num+1, items[num].text);
    }

    do                           /* Now prompt for a reply */
    {    
        printf("Select > ");
    }
    while (1 == scanf("%d", &sel)  &&  !(sel>=1  &&  sel<=num));

    items[sel-1].pfunc();        /* Execute the command.... */
}


void PrintHello (void)
{
    printf("Bonjour\n");
}


void PrintBye (void)
{
    printf("Au revoir\n");
}

