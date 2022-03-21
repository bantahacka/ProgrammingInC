/************************************************************************
 *                                                                      *
 *   view.c   Structures - Qu. 6 (Optional) Code Template               *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* First, the Union Template ... */

union View
{
    int     i_view;       /* int interpretation      */
    char    c_view[4];    /* 4 chars interpretation  */
};                        /* assumed (non-standard)  */

int main(void)
{
    union View memchunk[20];   /* Not initialised */
    int memloc;

    /* Code here for displaying local memory as   */
    /*      an integer                            */
    /* and  4 characters  (non-standard)          */

    return 0;
}

