/*********************************************************************
 *                                                                   
 *  Filename:     DSTACK.H
 *  Directory:    MODULAR
 *
 *  Description:  Public interface for the Stack.
 *
 *********************************************************************/

/*   StackInit  - Clears the stack                 */ 
/*   StackPush  - Pushes a double value onto stack */ 
/*   StackPop   - Removes a value from the stack   */ 

void   StackInit(void);
void   StackPush(double x);
double StackPop(void);