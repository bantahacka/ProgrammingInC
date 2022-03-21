/************************************************************************
 *                                                                      *
 *   lines2.c Input and Output - Qu. 2  Model Solution                  *
 *                                                                      *
 *               WARNING   This program is not portable;                *
 *               it uses the non-standard getch() function.             *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>  /* For the exit function               */

#define FILENAME 20
#define LINES_PER_PAGE  24

int main(void)
{
    char    name[FILENAME + 1];   /* read file name into this */
    FILE    *fh;                  /* file handle              */
    int     c;                    /* character for input      */
    int     lc;                   /* line count               */


    printf("Please enter file name: ");
    scanf("%20s", name);

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
                getchar();    /* wait for key press   */
                putchar('\n');  
                lc = 0;
	        }
        }
        fclose (fh);
    }
    return 0;
}


/************************************************************************
 *                                                                      
 *   An alternative solution follows, using fgets and fputs             
 *                                                                      
 *
 *
 *
 *
 *  int main(void)
 *	{
 *
 *      FILE *  file_point;
 *      char    file_name[FILENAME],
 *              my_buff[BUFSIZ];
 *      int     line_count = 0;
 *      int     dummy;
 *
 *      printf("Please enter file ID for display on the screen : ");
 *      scanf("%20s", file_name);
 *      file_point = fopen(file_name, "r");
 *      if (file_point == NULL)
 *      {
 *          fprintf(stderr, "problem with file open\n");
 *      }
 *      else
 *      {
 *          while ((fgets (my_buff, BUFSIZ, file_point)) != NULL)
 *          {
 *              puts(my_buff);
 *              line_count++ ;
 *              if (line_count == 16)
 *              {
 *                  printf("\nPress any key for more");
 *                  dummy = getchar();        
 *                  system("cls");                  
 *                  line_count = 0;
 *              }
 *          }
 *      }
 *      fclose(file_point);
 *      printf("**** End of file reached ****\n");
 *
 *      return 0;
 *  }
 *
 ************************************************************************/