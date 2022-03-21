 /* Prototype */
int is_even(int);

#include <stdio.h>

int main(void)
{
   int x, y = 19;

   x = is_even(y);
	
   if (is_even(42))
      printf("Even\n");

   printf("%d\n", is_even(y+1));

   return 0;
}

/* Definition */
int is_even(int num)
{
    if (num % 2 ==0)
        return 1;
    else
        return 0 ;
}
