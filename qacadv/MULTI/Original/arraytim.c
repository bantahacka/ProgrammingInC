/*********************************************************************
 *                                                                   
 *  Filename:     ARRAYTIM.C
 *  Directory:    MULTI
 *
 *  Description:  This program measures and compares the efficiency
 *                of various techniques for initialising a large
 *                "multidimensional" array.
 *
 *                There is a checkArray function here to check that the
 *                array is COMPLETELY initialised.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <malloc.h>
#include <sys/types.h>
#include <assert.h>

enum timerOptions { Undefined, Start, Stop, Show };

void timer(enum timerOptions);


#define REP_COUNT 100
#define SIZE1     25
#define SIZE2     26
#define SIZE3     27


/* The functions:
 *
 * withIndex             using [ ] notation (three lots of)
 * withBasePointer       using base (ie integer) pointers
 * withArrayPointer      using array pointers (WRITTEN FOR YOU)
 * withMemset            using memset
 */
void withIndex(int a[][SIZE2][SIZE3]);
void withBasePointer(int a[][SIZE2][SIZE3]);
void withArrayPointer(int a[][SIZE2][SIZE3]);
void withMemset(int a[][SIZE2][SIZE3]);

void checkArray(int a[][SIZE2][SIZE3]);
void saltArray(int a[][SIZE2][SIZE3]);


int main(void)
{
    int             i;
    static int      bigarray[SIZE1][SIZE2][SIZE3];


    saltArray(bigarray);  /* fill with non-zeros */

    fprintf(stderr, "array is %d by %d by %d, total %ld elements\n",
                    SIZE1, SIZE2, SIZE3,
                    (long)SIZE1 * SIZE2 * SIZE3);
    
    fprintf(stderr, "\nindex notation: "); 
    timer(Start);
    for(i = 0; i < REP_COUNT; i++)
        withIndex(bigarray);
    timer(Stop);
    timer(Show);
    checkArray(bigarray);


    fprintf(stderr, "\nbase pointers: "); 
    timer(Start);
    for(i = 0; i < REP_COUNT; i++)
        withBasePointer(bigarray);
    timer(Stop);
    timer(Show);
    checkArray(bigarray);


    fprintf(stderr, "\narray pointers: "); 
    timer(Start);
    for(i = 0; i < REP_COUNT; i++)
        withArrayPointer(bigarray);
    timer(Stop);
    timer(Show);
    checkArray(bigarray);


    fprintf(stderr, "\nmemset: "); 
    timer(Start);
    for(i = 0; i < REP_COUNT; i++)
        withMemset(bigarray);
    timer(Stop);
    timer(Show);
    checkArray(bigarray);

    return 0;
}


void withIndex(int a[][SIZE2][SIZE3])
{
    int i, j, k;
        
    /* 3 lots of [ ] notation here please */


}


void withBasePointer(int a[][SIZE2][SIZE3])
{
    int * p;
    int * end;

    /* initialise pointer to start and end of array, use pointer to access
     * elements of the array
     */

}


void withArrayPointer(int a[][SIZE2][SIZE3])
{
    int (*pYZ)[SIZE2][SIZE3];
    int (*pZ)[SIZE3];
    int (*endpZ)[SIZE3];

    int * p;
    int * end;

    /* This is a real pain to code up
     */
    for(pYZ = &a[0]; pYZ < &a[SIZE1]; pYZ++)
    	for(pZ = *pYZ, endpZ = &pZ[SIZE2]; pZ < endpZ; pZ++)
            for(p = *pZ, end = &p[SIZE3]; p < end; p++)
                *p = 0;
}

void withMemset(int a[][SIZE2][SIZE3])
{
    /* Fairly straightforward call to memset here.                       */
    /* The difficult part is in calculating the size of the WHOLE array. */
    /* Don't think you can say "sizeof(a)" because it WONT work.         */
}



/* Check to see that all the locations in the array have been set to zero.
 * Then set them to one for next time.
 *
 * The checking is done with "base" pointers since these are the fastest
 * way to access the array. Then the problem becomes on finding an error
 * relating the offset back to [X][Y][Z] values.
 */
void checkArray(int a[][SIZE2][SIZE3])
{
    long       x, y, z;
    int *      p;
    int *      end;
    long  int  offset;
    long  int  count = 0;

    for(p = &a[0][0][0], end = &a[SIZE1][0][0]; p < end; p++) 
    {

        /* If the location is not zero complain !!
         */
        if(*p != 0) 
        {

            offset = (long)(p - &a[0][0][0]);
            x = offset / (SIZE2 * SIZE3);
            y = (offset - (x * SIZE2 * SIZE3)) / SIZE3;
            z =  offset - (x * SIZE2 * SIZE3) - (y * SIZE3);
            if(*p != 0 && count == 0)
                fprintf(stderr, "location [%ld][%ld][%ld] is not zero !!\n",
				                                x, y, z);
	        count++;
        }
        *p = 1;
    }
    if(count > 0)
        fprintf(stderr, "total of %d uninitialised element(s)\n", count);
    else
        fprintf(stderr, "the array was initialised correctly\n");
}


/* Put non zero values throughout the whole array
 */
void saltArray(int a[][SIZE2][SIZE3])
{
    int * p;
    int * end;

    for(p = &a[0][0][0], end = &a[SIZE1][0][0]; p < end; p++)
        *p = 1;
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

