/************************************************************************
 *                                                                      *
 *   lines1.c   Input and Output - Qu. 1 Model Solution                 *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#define FILENAME 20

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
        fprintf(stderr,"Could not open %s\n", name);
    }
    else
    {
        lc = 0;
        while ((c = getc(fh)) != EOF)
        {
            if (c == '\n')
                lc++;
        }
        printf("Lines in %s: %d\n", name, lc);
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
 *      char    file_name[FILENAME + 1],
 *              my_buff[BUFSIZ];
 *      int     line_count = 0;
 *
 *      printf("Please enter file ID for line count : ");
 *      scanf("%20s", file_name);
 *      file_point = fopen(file_name, "r");
 *      if (file_point == NULL)
 *      {
 *          fprintf(stderr, "Problem with file open\n");
 *      }
 *      else
 *      {
 *          while ((fgets (my_buff, BUFSIZ, file_point)) != NULL)
 *          {
 *              line_count ++;
 *          }
 *      }
 *      printf("Number of lines in %s is %d\n", file_name, line_count);
 *  
 *      return 0;
 *  }
 *
 ************************************************************************/
