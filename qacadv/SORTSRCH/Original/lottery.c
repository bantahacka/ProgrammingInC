/*********************************************************************
 *                                                                   
 *  Filename:     LOTTERY.C
 *  Directory:    SORTSRCH
 *
 *  Description:  This program prints out 6 random numbers suitable for
 *                submission to the National Lottery
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>           /* For time()                       */
#include <sys\types.h>      /* For the time_t type              */
#include <string.h>         /* For memcpy, believe it or not    */

#define LOTTERY_DRAWN   6   /* Draw six numbers                 */
#define LOTTERY_MIN     1   /* Lowest possible lottery number   */
#define LOTTERY_MAX     49  /* Highest possible lottery number  */

#define LOTTERY_RANGE   (LOTTERY_MAX - LOTTERY_MIN + 1)


int compInt(const void*, const void*);
int drawAndRemove(int a[], int* size);
int getRandInRange(int lower, int upper);


int main(void)
{
    int     i;
    int     ballsLeft;
    time_t  now;
    int     numbers[LOTTERY_RANGE]; /* All possible numbers     */
    int     drawn[LOTTERY_DRAWN];   /* The numbers drawn        */
    
    /* Generate the set of balls. Notice this will still work even
     * if they decide to pull a few out (like maybe start from 5 and
     * go up to 40).
     */
    for(i = 0; i < LOTTERY_RANGE; i++)
        numbers[i] = i + LOTTERY_MIN;

    /* Seed the random number generator
     */
    now = time(NULL);
    srand((unsigned)now);
    
    /* Start Arthur going
     */
    ballsLeft = LOTTERY_RANGE;
    for(i = 0; i < LOTTERY_DRAWN; i++)
        drawn[i] = drawAndRemove(numbers, &ballsLeft);

    /* Print them out
     */
    for(i = 0; i < LOTTERY_DRAWN; i++)
        printf("%3d ", drawn[i]);
        
    printf("\n");

    return 0;
}

/* This function is called with an array of integers and the number of
 * valid integers in the array. Since this second parameter is passed by
 * pointer, we can change it (i.e. decrease it) when a ball is drawn.
 *
 * For instance, lets say we have "1 2 3 4 5" in the set. The size of the
 * set is thus 5. If we draw 3, the set becomes "1 2 4 5" and the size
 * becomes 4.
 */
int drawAndRemove(int a[], int* size)
{
    int r;
    int drawn;
    
    /* Get a random index into the array. Remember this will start
     * at 0.
     */
    r = getRandInRange(0, *size - 1);
    
    /* This is the ball we have chosen
     */
    drawn = a[r];
    
    /* Now remove this ball from the set by copying all above it
     * downwards.
     */
    memcpy(&a[r], &a[r + 1], (*size - r  - 1) * sizeof(a[0]));
    
    /* Now there is one less ball
     */
    *size = *size - 1;
    
    return drawn;
}

/* Return a random number in the range specified
 */
int getRandInRange(int lowest, int highest)
{
    return (rand() % (highest - lowest)) + lowest;
}

/* Integer comparison function for qsort
 */
int compInt(const void* a, const void* b)
{
    const int * one = a;
    const int * two = b;
    
    return *one - *two;
}
