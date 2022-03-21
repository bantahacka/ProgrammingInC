/* Input and Output - File Access Example */
#include <stdio.h>

int main(void)
{
	char in_name[25], out_name[25];
	FILE *in_file, *out_file;
	int ch;

	printf("Enter name of file to be copied: \n");
	scanf("%24s", in_name);
	printf("Enter name of output file: \n");
	scanf("%24s", out_name);

	in_file = fopen(in_name, "r");
	if (in_file == NULL)
        fprintf(stderr, "Can't open %s for reading .\n", in_name);
	else
	{
		out_file = fopen(out_name,"w");
	    if (out_file == NULL)
            fprintf(stderr, "Can't open %s for writing.\n", out_name);
		else
		{
			while ((ch = getc(in_file)) !=EOF)
				putc( ch, out_file );
			printf("File has been copied.\n");
			fclose(out_file);
		}
		fclose(in_file);
	}

    return 0;
}
