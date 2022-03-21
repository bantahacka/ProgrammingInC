/************************************************************************
 *                                                                      *
 *   wrt_nums.c Functions - Qu. 1 Model Solution                        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* This is the prototype for write_nums. Remember, this is information   */
/* for the compiler to enable it to check type and number of parameters  */
/* and the return value. In this case there is no return value, so we    */
/* use void.                                                             */

void write_nums(int, int);

/* An alternative form for this prototype would be:                      */
/*                                                                       */
/* void write_nums(int lower_bound, int upper_bound);                    */
/*                                                                       */
/* This has the same effect, but the identifier names after the types    */
/* are useful for documenation (they are otherwise ignored).             */


/* From now on we will use the form "void main(void)" to define function */
/* main because it has no parameters and returns no result               */

int main(void)
{
    int first, last;

    printf("Enter 2 numbers: ");
    scanf("%d %d", &first, &last);

    /* Call function */
    
    write_nums(first, last);

    return 0;
}


/*                                                                       */
/* Here is the definition of the function. It should match the prototype */
/* given above, but the parameters must be given names (in this case,    */
/* x and y). If we had used the alternative prototype form the names do  */
/* not need to be the same.                                              */
/*                                                                       */

void write_nums(int x, int y)                   
{               
    int count;
    
    for(count = x+1; count < y; count++)
        printf("%d ", count);


    /*  Alternatively, the for loop could be written as:
     *
     *   for(x++; x < y; x++)
     *       printf("%d ", x);
     *
     *   This uses x as a counter. This changes the value of x with
     *   the function but has no effect on any variables outside it.
     *   Writing the code in this way means that we don't need a local
     *   variable as a counter.
     *
     *   It is also possible to use a while loop.
     */

    printf("\n");
}
