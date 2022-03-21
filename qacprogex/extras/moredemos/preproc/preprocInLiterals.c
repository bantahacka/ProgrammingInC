
/* Comment */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum suit { clubs, hearts, spades, diamonds };
typedef enum suit suit_t;
typedef enum season {sp,su,a,w} season_t;
int stuff(void);

#define SIZE_STR(a) #a
#define DOIT(b) SIZE_STR(b)
#define SIZE 5
#define FORMATSTR 12

int main(int argc, char * argv[], char * envv[])
{
	int i = 42;
	char format[12] = "%";

/*
	for (i = 0; i < argc; i++)
	{
	     printf("%s%c", argv[i], 
		   (i < argc - 1) ? ' ' : '\n');
	}
*/

	strcat(strcat(format,DOIT(SIZE)), "s\n"));
	/*printf("%" "5" "s\n", "Hello1");


	printf("%" DOIT(SIZE) "s\n", "Hello");*/
	printf(format, "Hello");
	
	
	for (i = 0; i < 10; i++)
	{
		printf("%s\n", envv[i]);
	}

	return 0;

}

int stuff(void)
{
    suit_t trumps = clubs;
	int x = 0;
	scanf("%d", &x);

	if (x > 0)
	{
		puts("Positive\n");
		puts("Yes it really is positive\n");
	}
	else
	{
		puts("negative\n");
		puts("Yes it really is negative\n");
	}

    return 0;
}

