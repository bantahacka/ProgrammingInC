/************************************************************************
 *                                                                      *
 *   p_larger.c   Pointers/Functions - Qu. 3 (Optional) Model Solution  *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

int *p_larger(int *, int *);

int main(void)
{
    int *p, x = 9, y = 12;
    p = p_larger(&x, &y);
    printf("%d\n", *p);

    return 0;
}


int *p_larger(int *p1, int *p2)
{
    int *ans;

    if (*p1 > *p2)
        ans = p1;
    else
        ans = p2;

    return ans;

    /* Alternatively
     *
     *       return (*p1 > *p2) ? p1 : p2;
     */
}

