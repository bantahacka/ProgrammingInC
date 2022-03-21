/* Decision Making - The switch Statement */
#include <stdio.h>

int main(void)
{
	int legs = 6 ;

	printf("How many legs\t");
	scanf("%d", &legs);

	switch (legs)
	{
		case 1 :
			printf ("Flamingo\n") ;
			break ;
		case 2 :
			printf ("Ape\n") ;
			break ;
		case 4 :
			printf ("Dog\n") ;
			break ;
		default :
			printf ("Insect\n") ;
			break ;
	}

	return 0;
}
