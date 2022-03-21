/*********************************************************************
 *                                                                   
 *  Filename:     USESTACK.C
 *  Directory:    MODULAR\SOLUTION
 *
 *  Description:  Test harness for the DStack module.
 *
 *********************************************************************/

#include <stdio.h>
#include "dstack.h"

int main(void)
{
    double d1,d2,d3,d4;

    printf("Testing the stack now.....\n");

    StackInit();

    StackPush(2.0);
    StackPush(3.0);

    d1 = StackPop();  /* Should be 3.0 */

    StackPush(4.0);

    d2 = StackPop();  /* Should be 4.0 */
    d3 = StackPop();  /* Should be 2.0 */

    StackPush(22.0);
    StackInit();      /* 22.0 will be lost... */
    StackPush(99.0);
    d4 = StackPop();  /* Should be 99.0 */

    if (d1==3.0  &&  d2==4.0  &&  d3==2.0  &&  d4==99.0)
        printf("Seems ok...\n");
    else
        printf("Seems like something has gone wrong...\n");

    return 0;
}
