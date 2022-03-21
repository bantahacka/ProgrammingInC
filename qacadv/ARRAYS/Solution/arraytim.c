/*********************************************************************
 *                                                                   
 *  Filename:     ARRAYTIM.C
 *  Directory:    ARRAYS\SOLUTION
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
void init1 (char array[]);            /* Initialisation function #1 */
void init2 (char *pArray);            /* Initialisation function #2 */
void init3 (char *pArray);            /* Initialisation function #3 */


#define SIZE      30000               /* Size of the big array  */ 
#define REP_COUNT 10000               /* Repeat each operation  */
                                     /* 100 times for accuracy */ 

int main(void)
{
    static  char  bigarray[SIZE];     /* Large character array       */
    int           rep;                /* Repeat count                */


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

    for(rep = 0; rep < REP_COUNT; rep++)
        init1(bigarray);              /* Array/index notation */

    timer(Stop);
    timer(Show);

    /*  
     *  Call your 2nd initialisation function 100 times and measure the
     *  elapsed time for this operation.
     */
    timer(Start);

    for(rep = 0; rep < REP_COUNT; rep++)
        init2(bigarray);              /* Array/index notation */

    timer(Stop);
    timer(Show);

    
    /*  
     *  Call your 3rd initialisation function 100 times and measure the
     *  elapsed time for this operation.
     */
    timer(Start);

    for(rep = 0; rep < REP_COUNT; rep++)
        init3(bigarray);              /* Using memset() */

    timer(Stop);
    timer(Show);

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


void init1(char array[])              /* Array / index notation */
{
    int i;                 

    for (i = 0; i < SIZE; i++)
        array[i] = '\0';   
}

 
void init2(char *pArray)              /* Pointer / offset notation */
{
    char *pEnd = &pArray[SIZE];   

    while (pArray < pEnd)
        *pArray++ = '\0';
}


void init3(char *pArray)              /* Using memset() */
{
    /* Notice in the following that "SIZE" would have to have read
     *
     *			SIZE * sizeof(*pArray)
     *
     * if we were dealing with anything other than characters
     */
    memset(pArray, '\0', SIZE);
}

