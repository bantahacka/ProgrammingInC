/* Decision Making - break/continue examples  */

#define REC_LIMIT               1000
#define OK                      0
#define SEVERE_ERROR            -1
#define CURRENT_REC_ERROR       -2

#include <stdio.h>

int main(void)
{
	int record_count = 0;
	int rec_code = OK;

	while (record_count < REC_LIMIT)
	{
		record_count++;
		if (record_count == 666)
		{
		    rec_code = SEVERE_ERROR;
		    printf("Severe Record Error on record number %d\t",
			    record_count);
		    printf("Press <ENTER>\n\n");
		    getchar();

		}

		if (rec_code == SEVERE_ERROR)
			break;
	}
	printf("Broken out of loop on record number %d\n\n\n", record_count);

	record_count = 0;
	rec_code = OK;

	while (record_count < REC_LIMIT)
	{
		record_count++;
		if (record_count == 13)
		{
		    rec_code = CURRENT_REC_ERROR;
		    printf("Current Record Error on record number %d\t",
			    record_count);
		    printf("Press <ENTER>\n\n");
		    getchar();
		}
		if (rec_code == CURRENT_REC_ERROR)
			continue;
	}
	printf("Quit loop on record number %d\n", record_count);

	return 0;

}



