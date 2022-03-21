/*
   LGCADV1 Chapter 12
   Clive Darke

   40000 items took 4.61 seconds on a PIII 500 (Debug)
   20000 items took 1.04 seconds on a PIII 500 (Debug)
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <time.h>

#define NO_OF_ITEMS (40000)

int mycomp(const void *a, const void *b);

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

   qsort(p, NO_OF_ITEMS, sizeof(int), mycomp);

   end = clock ();

   printf ("Qsort sort of %d items took %0.2lf seconds (%d ticks)\n",
      NO_OF_ITEMS, (double)(end-start) / CLOCKS_PER_SEC, (end-start));
   printf ("Kindly press a key to continue...\n");
   getchar();

   return 0;
}

int mycomp(const void *a, const void *b)
{
    const int *x = a;
    const int *y = b;

    return (*x - *y);
}



