/************************************************************************
 *                                                                      *
 *   view.c   Structures - Qu. 6 (Optional) Model Solution              *
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

    for (memloc = 0 ; memloc < 20 ; memloc ++)
    {
        printf("As an integer, memchunk[%2d] contains 0x%08x  ",
                memloc, memchunk[memloc].i_view);

        printf("and as characters, %c%c%c%c\n",
                memchunk[memloc].c_view[0],
                memchunk[memloc].c_view[1],
                memchunk[memloc].c_view[2],
                memchunk[memloc].c_view[3]);
    }

    return 0;
}

