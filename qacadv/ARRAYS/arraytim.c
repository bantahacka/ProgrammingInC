/*********************************************************************
 *                                                                   
 *  Filename:     ARRAYTIM.C
 *  Directory:    ARRAYS
 *
 *  Description:  This program measures and compares the efficiency
 *                of various techniques for initialising a large array.
 *
 *  NOTE: 
 *  After you have finished the testing, find out how to set the 
 *  optimiser on your compiler and re-run the tests.
 *
 *  Are there any differences ?
 *
 *********************************************************************/

#include <stdio.h>                    /* printf() */
#include <string.h>                   /* memset() */
#include <time.h>                     /* clock()  */

enum timerOptions { Undefined, Start, Stop, Show };

void timer(enum timerOptions);


/*** Place 3 prototypes here for functions to initialise an array      ***/
/*** using array/index notation, pointer/offset notation, and memset() ***/


#define SIZE      30000               /* Size of the big array  */ 
#define REP_COUNT 100                 /* Repeat each operation  */
                                      /* 100 times for accuracy */ 

int main(void)
{
    static  char  bigarray[SIZE];     /* Large character array       */


    /* First, call timer(Start) to start the timer ticking. Then set up
     * a loop of 100 iterations; on each iteration, call your 1st
     * initialisation function to initialise bigarray[] with '\0'
     * characters. (By repeating the initialisation 100 times we get
     * more accurate time measurements).
     * At the end of the loop, call timer(Stop) to stop the timer and
     * timer(Show) to print the total time elapsed during these 100
     * initialisations.
     */
    timer(Start);

    /* loop in here */

    timer(Stop);
    timer(Show);

    /*  
     *  Call your 2nd initialisation function 100 times and measure the
     *  elapsed time for this operation.
     */

    
    /*  
     *  Call your 3rd initialisation function 100 times and measure the
     *  elapsed time for this operation.
     */

     return 0;
}

/* This function does all the timing stuff
 */
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

/*** Place your three initialisation functions here ***/


