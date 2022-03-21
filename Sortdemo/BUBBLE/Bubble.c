/*
   LGCADV1 Chapter 12
   Clive Darke

   40000 items took 38.66 seconds on a PIII 500 (Debug)
   20000 items took  9.78 seconds on a PIII 500 (Debug)
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define NO_OF_ITEMS (20000)

void bubble(int *p, int num);

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

   bubble(p, NO_OF_ITEMS);

   end = clock ();

   printf ("Bubble sort of %d items took %0.2lf seconds (%d ticks)\n",
      NO_OF_ITEMS, (double)(end-start) / CLOCKS_PER_SEC, (end-start));
   printf ("Kindly press a key to continue...\n");
   getchar();

   return 0;
}




void bubble(int *p, int num)
    {
    int i, j, t;

    for (i = num; i >= 1; i--)
         for (j = 1; j < i; j++)
              if (p[j - 1] > p[j])
                   {
                   t = p[j - 1];
                   p[j - 1] = p[j];
                   p[j] = t;
                   }
    return;
    }

