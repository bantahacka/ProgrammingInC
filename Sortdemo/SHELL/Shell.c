/*
   LGCADV1 Chapter 12
   Clive Darke

   40000 items took 12.79 seconds on a PIII 500 (Debug)
   20000 items took  3.07 seconds on a PIII 500 (Debug)
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define NO_OF_ITEMS (20000)

void shell(int *p, int num);

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

   shell(p, NO_OF_ITEMS);

   end = clock ();

   printf ("Shell sort of %d items took %0.2lf seconds (%d ticks)\n",
      NO_OF_ITEMS, (double)(end-start) / CLOCKS_PER_SEC, (end-start));
   printf ("Kindly press a key to continue...\n");
   getchar();

   return 0;
}


void shell(int *p, int num)
    {
    int i, j, h, v;

    for (h = 1; h <= num / 9; h = 3 * h + 1)
         ;
    for ( ; h > 0; h /= 3)
         {
         for (i = h; i < num; i += h)
              {
              v = p[i];
              j = i;
	          while (j > (h - 1) && p[j - h] > v)
                   {
	               p[j] = p[j - h];
                   j -= h;
                   }
	          p[j] = v;
              }
         }
    return;
    }

