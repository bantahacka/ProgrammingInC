/*
   LGCADV1 Chapter 12
   Clive Darke

   40000 items took 12.36 seconds on a PIII 500 (Debug)
   20000 items took  3.02 seconds on a PIII 500 (Debug)
*/

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define NO_OF_ITEMS (20000)

void insert(int *p, int num);

int main (int argc, char *argv[])
{
   int i;
   clock_t start, end;
   int *p = (int *)malloc (NO_OF_ITEMS * sizeof(int));

   if (!p)
   {
      fprintf (stderr, "Bit low on the old memory there...\n");
      exit (ENOMEM);
   }

   for (i = 0; i < NO_OF_ITEMS; i++)
      p[i] = 219 | rand() % 16 << 8;

   start = clock ();

   insert(p, NO_OF_ITEMS);

   end = clock ();

   printf ("Insert sort of %d items took %0.2lf seconds (%d ticks)\n",
      NO_OF_ITEMS, (double)(end-start) / CLOCKS_PER_SEC, (end-start));
   printf ("Kindly press a key to continue...\n");
   getchar();

   return 0;
}

void insert(int *p, int num)
    {
    int i, j, v;

    for (i = 1; i < num; i++)
         {
         v = p[i];
         j = i;
	     while (j > 0 && p[j - 1] > v)
              {
	          p[j] = p[j - 1];
              --j;
              }
	     p[j] = v;
         }
    return;
    }

