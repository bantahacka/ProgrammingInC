/************************************************************************
 *                                                                      *
 *   drawv.c Looping Constructs - Qu. 4 (Optional) Model Solution       *
 *                                                                      *
 ************************************************************************/
#include <stdio.h>

/* This is version A (see below for version B) */

int main(void)
{
    int i;  /* used as loop counter */
    int j;  /* used as loop counter */
    int h;  /* user specified height */

    /* get the height from the user */
    printf("Enter height: ");
    scanf("%d", &h);

    /* print the first (h - 1) lines of the v */
    for(i = h; i > 1; i--)
    {
        for(j = 0; j < (h - i); j++)
            printf(" ");
        printf("v");

		for(j = 0; j < (2 * i - 3); j++)
            printf(" ");
        printf("v\n");
    }
    
    /* Print last line which has only one v in it */
    for(j = 0; j < (h -1); j++)
        printf(" ");
    printf("v\n");

    return 0;
}


/* This is version B */
int main_version_b(void)
{
    int column = 0;     /* used as loop counter    */
    int row = 0;        /* used as loop counter    */
    int h = 0;          /* user-specified height   */
    int colwidth = 0;   /* maximum width of output */

    /* get the height from the user */
    do
    {
		printf("Enter height: ");
		scanf("%d", &h);
    }
    while (h <= 0 || h > 23);

    colwidth = 2 * h - 1;  /* set maximum width */

    /* prints a 'v' in the appropriate position */

    for(row = 0; row < h; row++)
    {
		for(column = 0; column < colwidth; column++)
		{
			if (column == row || column == colwidth - 1 - row )
				printf("v");
			else
				printf(" ");
		}
		printf("\n");
    }

    return 0;
}
