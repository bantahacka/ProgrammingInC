/************************************************************************
 *                                                                      *
 *   lines3.c Input and Output - Qu. 3  Model Solution                  *
 *                                                                      *
 *               WARNING   This program is not portable;                *
 *               it uses the non-standard getch() function.             *
 *                                                                      *
 ************************************************************************/


#include <stdio.h>
#include <string.h>  /* For the strncpy function            */
#include <stdlib.h>  /* For the system function             */

#define FILENAME 20
#define LINES_PER_PAGE  24

int main(int argc, char *argv[])
{
    char    name[FILENAME + 1];   /* read file name into this */
    FILE    *fh;                  /* file handle              */
    int     c;                    /* character for input      */
    int     lc;                   /* line count               */

    int argcount = argc;

    switch (argcount)
    {
    case 2 :
        /* strcpy(name, argv[1]) is the "obvious" code here, but */
        /* this will foul up if argv[1] is too long for name     */

        strncpy(name, argv[1], sizeof(name)-1);
        name[sizeof(name)-1] = '\0';
        break;

    case 1 :
        printf("Please enter file name: ");
        scanf("%20s", name);
        break;

    default :
        fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
        return -1;   /* quit program with error code */
    }


    if ((fh = fopen(name, "r")) == NULL)
    {
        fprintf(stderr, "Could not open %s\n", name);
    }
    else
    {
        lc = 0;
        while ((c = getc(fh)) != EOF)
        {
            putchar(c);
            if (c == '\n' && ++lc == LINES_PER_PAGE)
            {
                printf("---- Hit a key -----");
                getchar();        /* wait for key press   */
                system("cls");  /* and clear screen */
                putchar('\n');  
                lc = 0;
	        }
        }
        fclose (fh);
    }

    return 0;        /* program completed ok */
}


