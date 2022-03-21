 /* Example of use of a nested macro */

#include <stdio.h>
#include <string.h>

#define NAMESIZE 21
#define BUILDPERCENT(X) "%" MAKESTRING(X)
#define MAKESTRING(X) #X
#define SPECIFIER "s"
#define FORMATSIZE 5

int main(void)
{
	char name[NAMESIZE];
	char format[FORMATSIZE] = BUILDPERCENT(NAMESIZE);

	strcat(format, SPECIFIER);

	printf("Please type in name ");

	scanf(format, name);

	printf("Hello %s\n", name);

	return 0;
}