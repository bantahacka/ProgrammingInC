/*
   LGCADV1 Chapter 12
   Clive Darke

   40000 items took 18.34 seconds on a PIII 500 (Debug)
   20000 items took  4.56 seconds on a PIII 500 (Debug)
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define NO_OF_ITEMS (40000)

void select(int *p, int num);

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

   select(p, NO_OF_ITEMS);

   end = clock ();

   printf ("Select sort of %d items took %0.2lf seconds (%d ticks)\n",
      NO_OF_ITEMS, (double)(end-start) / CLOCKS_PER_SEC, (end-start));
   printf ("Kindly press a key to continue...\n");
   getchar();

   return 0;
}

void select(int *p, int num)
{
    int i, j, min, t;

    for (i = 0; i < num - 1; i++)
    {
        min = i;
        for (j = i + 1; j < num; j++)
        {
            if (p[j] < p[min])
                min = j;
        }
        t = p[min];
        p[min] = p[i];
        p[i] = t;
    }
    return;
}

