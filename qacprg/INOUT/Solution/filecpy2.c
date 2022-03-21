/************************************************************************
 *                                                                      *
 *   filecpy2.sol Input and Output - Qu. 5 (Optional) Model Solution    *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>   /* also for BUFSIZ, FILE, and size_t */
#include <string.h>  /* for strncpy */

#define FILENAME 20

int fcopy (char *infilename, char *outfilename);

int main(int argc, char *argv[])
{
    char in_name[FILENAME + 1], out_name[FILENAME + 1];
    int errorcode = 0;
    int argcount = argc;

    switch (argcount)
    {
    case 3 :
		strncpy(in_name, argv[1], sizeof(in_name)-1);
		in_name[sizeof(in_name)-1] = '\0';
		strncpy(out_name, argv[2], sizeof(out_name)-1);
		out_name[sizeof(out_name)-1] = '\0';
		break;

    case 2 :
		/* assume file name is in file */
		strncpy(in_name, argv[1], sizeof(in_name)-1);
		in_name[sizeof(in_name)-1] = '\0';
		printf("Enter name of output file: \n");
		scanf("%20s", out_name);
		break;

    case 1 :
		printf("Enter name of file to be copied: \n");
		scanf("%20s", in_name);
		printf("Enter name of output file: \n");
		scanf("%20s", out_name);
		break;

    default :
                fprintf(stderr, "Usage: %s <file_from> <file_to>\n", argv[0]);
		return -1;   /* quit program with error code */
    }

	errorcode = fcopy(in_name, out_name);

	if (!errorcode)
		return 0;       /* everything OK */
	else
		return 1;       /* To be interpreted by Operating System */

}

int fcopy (char *in, char *out)
{
	FILE *in_file, *out_file;
	char buffer[BUFSIZ];   /* used by fread and fwrite            */
	size_t numbytes = 0;   /* number returned by fread and fwrite */
	size_t size = 1;       /* size of unit, a byte in this case   */

	in_file = fopen(in, "r");
	if (in_file == NULL)
	{
                fprintf(stderr, "Can't open %s for reading .\n", in);
		return 1;   /* NO GOOD */
	}
	else
	{
		out_file = fopen(out,"w");
		if (out_file == NULL)
		{
                        fprintf(stderr, "Can't open %s for writing.\n", out);
			return 2;    /* NO GOOD */
		}
		else
		{
			while ((numbytes = fread(buffer, size, BUFSIZ, in_file)) != 0)
				fwrite(buffer, size, numbytes, out_file);
			printf("File has been copied.\n");
			fclose(out_file);
		}
		fclose(in_file);
		return 0;           /* ALL's WELL */
	}
}
