/* Pointers - Exercise on "*" and "&"    */

#include <stdio.h>

int main(void)
{
	int a = 46;
	int b = 19;
	int c;

	int *p = &a;

	printf("&a is %p\n", &a);
	printf("&b is %p\n", &b);
	printf("&c is %p\n", &c);
	printf("p is %p\n\n", p);

	c = *p;         printf("c is %d\n", c);

	p = &b;         printf("p is %p\n", p);

	c = *p;         printf("c is %d\n", c);

	b = 77;         printf("b is %d\n", b);

	c = *p;         printf("c is %d\n", c);

	return 0;
}

