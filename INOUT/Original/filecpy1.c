/************************************************************************
 *                                                                      *
 *   filecpy1.c   Input and Output - Qu. 5 (Optional) Code Template     *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>   /* also for BUFSIZ, FILE, and size_t */

#define FILENAME 20

int fcopy (char *infilename, char *outfilename);

int main(void)
{
	char in_name[FILENAME + 1], out_name[FILENAME + 1];
	int errorcode = 0;

	printf("Enter name of file to be copied: \n");
	scanf("%20s", in_name);
	printf("Enter name of output file: \n");
	scanf("%20s", out_name);

	errorcode = fcopy (in_name, out_name);
	if (!errorcode)
		return 0;       /* everything OK */
	else
		return 1;       /* To be interpreted by Operating System */

}

