/* #if example */

#include <stdio.h>

#define USD 1
#define UK  2
#define DM  3
/* ... */

#define CURRENCY USD    /* CHANGE THIS LINE ONLY */

#if CURRENCY == USD
const char country[] = "United States of America";
#define SYMBOL '$'

#elif CURRENCY == UK
const char country[] = "United Kingdom";
#define SYMBOL 'œ'

#elif CURRENCY == DM
const char country[] = "Germany";
#define SYMBOL 'M'

#endif

int main(void)
{
	printf("Your country of choice is %s\n", country);
	printf("The monetary symbol is %c\n", SYMBOL);

	return 0;
}

