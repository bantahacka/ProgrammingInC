/* Arrays/Strings - Library Support Functions  */

#include <string.h>
#include <stdio.h>

int main(void)
{
	int len;
	char s1[] = "Hi there";
	char s2[50];

	len = strlen(s1);
	printf("s1 is %d long\n", len);

	strcpy(s2, s1); /* Effectively like s2 = s1 */
	printf("%s world\n", s2);

    return 0;
}




