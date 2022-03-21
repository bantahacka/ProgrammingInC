/* Decision Making - if Statement: Form 3 */
#include <stdio.h>

int main(void)
{
	int legs = 6 ;

	printf("How many legs\t");
	scanf("%d", &legs);

	if ( legs == 1 )
		printf ("Flamingo\n") ;
	else if ( legs == 2 )
		printf ("Ape\n") ;
	else if ( legs == 4 )
		printf ("Dog\n") ;
	else
		printf ("Insect\n") ;

	return 0;
}
