/* Decision Making -  Case without Break   */

/* That 12 Partridges thing ... */

#include <stdio.h>

int main(void)
{
	int verse;

	for (verse = 1; verse <= 5; verse ++)
	{
		printf("On the ");
		switch(verse)
		{
			case 1: printf("1st");  break;
			case 2: printf("2nd");  break;
			case 3: printf("3rd");  break;
			case 4: printf("4th");  break;
			case 5: printf("5th");  break;
		}
		printf(" day of Christmas my true love sent to me:\n");
		switch(verse)
		{
			case 5: printf("five gold rings, ");
			case 4: printf("four calling birds, ");
			case 3: printf("three french hens, \n");
			case 2: printf("two turtle doves, and ");
			case 1: printf("a partridge in a pear tree\n\n");
		}
	}
	return 0;
}
