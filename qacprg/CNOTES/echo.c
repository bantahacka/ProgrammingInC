/* Input and Output - Character I/O getchar and putchar */

#include <stdio.h>

void echo(void);

int main(void)
{
	printf("Please type here:\n");
	echo();

    return 0;
}


void echo(void)
{
	int c;

	while((c = getchar()) != EOF)
		putchar(c);

}

