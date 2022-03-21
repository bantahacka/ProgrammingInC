#include <stdio.h>
#define NAME 30

struct Link
{
	char name [NAME + 1];
	struct Link * next;
};

int main(void)
{
	struct Link n1 ={"Pat", NULL} ;
	struct Link n2 ={"Jo", &n1};
	struct Link n3 ={"Terry", &n2} ;
	struct Link *lp ;

	lp = &n3; 	/* Attach to start */
	
	while (lp != NULL)
	{
		printf("%s\n", lp->name);
		lp = lp->next; 	/* move to next Link */
	}
 
    return 0;
}
