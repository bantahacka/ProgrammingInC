/************************************************************************
 *                                                                      *
 *   tdef2.c  Further Data Types - Qu. 2 Model Solution (part 2)        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>         /* For system and exit functions  */
#include <string.h>         /* For the strcmp function        */

#include "tdef.h"           /* For definition of POINT   */
                            /*  and prototypes           */

int main(void)
{
    POINT P1;

    printf("Please type in the co-ordinates and colour\n");
    printf("...thus 120,34,8\t");

    Pscanf("%P", &P1);
    Pprintf("%P", &P1);

    return 0;
}

void Pscanf(const char * format, POINT * pptr)
{
    if (strcmp(format, "%P") != 0)
    {
        printf("Wrong format string\n");
        exit (-1);
    }

    scanf("%d,%d,%hd", &pptr->x, &pptr->y, &pptr->col);
    return;
}

void Pprintf(const char * format, POINT * pptr)
{
    if (strcmp(format, "%P") != 0)
    {
        printf("Wrong format string\n");
        exit (-1);
    }

    printf("x = %d, y = %d, colour code = %hd",
	                pptr->x, pptr->y, pptr->col);
    return;
}
