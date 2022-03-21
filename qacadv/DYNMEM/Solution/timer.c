/*********************************************************************
 *                                                                   
 *  Filename:     TIMER.C
 *  Directory:    DYNMEM\SOLUTION
 *
 *  Description:  This file implements a useful timer function.
 *
 *********************************************************************/

#include <time.h>
#include <stdio.h>
#include "timer.h"

void timer(enum timerOptions whatToDo)
{
    static	time_t  t;
    static	enum    timerOptions	state = Undefined;

    switch(whatToDo) 
    {
        case Start:
            t = clock();
            state = Start;
            break;

        case Stop:
            if(state != Start) 
            {
                printf("Can only stop a timer that has been started\n");
                return;
            }
            state = Stop;
            t = clock() - t;
            break;
	  
        case Show:
            if(state != Stop) 
            {
                printf("Can only show a stopped timer!\n");
                return;
            }
            printf("%llu units have elapsed\n", t);
            break;
    }
}
