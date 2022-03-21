/************************************************************************
 *                                                                      *
 *   anytype.c   Structures - Qu. 5 (Optional) Code Template            *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

union Values
{
    char c_val;
    int i_val;
    float f_val;
};

struct Anytype
{
    int type;
    union Values value;     /* refer to course notes */
};

void print_anytype(struct Anytype) ; /* Pass by value */

int main(void)
{
    struct Anytype a1;
    struct Anytype a2;
    struct Anytype a3;

    a1.type = 1;                    /* prepare for a char  */
    a1.value.c_val = 'Z';

    a2.type = 2;                    /* prepare for a int   */
    a2.value.i_val = 42;

    a3.type = 3;                    /* prepare for a float */
    a3.value.f_val = 98.6F;



    print_anytype(a1);      /* Displays a char  */
    printf("\n");
    print_anytype(a2);      /* Displays a int   */
    printf("\n");
    print_anytype(a3);      /* Displays a float */
    printf("\n");

    return 0;
}

/* print_anytype function definition here */
