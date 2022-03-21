/* Input and Output - File Access Example */
#include <stdio.h>

int fcopy (char *in, char *out);

int main(void)
{
	char in_name[25], out_name[25];
	int errorcode = 0;

	printf("Enter name of file to be copied: \n");
	scanf("%24s", in_name);
	printf("Enter name of output file: \n");
	scanf("%24s", out_name);
	if(errorcode = fcopy (in_name, out_name))
	{        
        fprintf(stderr, "Error copying file\n");
	}

    return 0;
}

int fcopy (char *in, char *out)
{
	FILE *in_file, *out_file;
	int ch;

	in_file = fopen(in, "r");
	if (in_file == NULL)
	{
        fprintf(stderr, "Can't open %s for reading .\n", in);
		return 1;
	}
	else
	{
		out_file = fopen(out,"w");
		if (out_file == NULL)
		{
            fprintf(stderr, "Can't open %s for writing.\n", out);
			return 2;
		}
		else
		{
			while ((ch = getc(in_file)) !=EOF)
				putc(ch, out_file);
			printf("File has been copied.\n");
			fclose(out_file);
		}
		fclose(in_file);
		return 0;
	}
}
