/************************************************************************
 *                                                                      *
 *   tdef1.c Further Data Types - Qu. 2 Model Solution (part 1)         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>         /* for the system function  */

#include "tdef.h"           /* for definition of POINT  */
                            /*  and prototypes          */

int main(void)
{
    POINT P1;

    Pinitialise(&P1);
    Pprint(&P1);

    return 0;
}

void Pinitialise(POINT * pptr)
{
    printf("Please type in the co-ordinates and colour\n");
    printf("...thus 120,34,8\t");
    scanf("%d,%d,%hd", &pptr->x, &pptr->y, &pptr->col);
	return;
}

void Pprint(POINT * pptr)
{
    printf("x = %d, y = %d, colour code = %hd\n",
                    pptr->x, pptr->y, pptr->col);
    return;
}
