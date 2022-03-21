/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        stepdirs.c                                            */
/*      DESCRIPTION: Program to locate system, hidden, and read-only files */
/*                                                                         */
/*      Clive Darke: Convered to Win32                                     */
/*                                                                         */
/***************************************************************************/
#include <stdio.h>		/* For printf etc	  */
#include <windows.h>	/* For dos file functions */

#define MAXLEN 35

int main(int argc, char *argv[])
{
    static char dirname[MAXLEN+1];	/* Filename buffer  */
    WIN32_FIND_DATA finfo;		/* File information */
    HANDLE hFindFile;
    int   count = 0;
    BOOL bResult;

    /*
     * Prompt for path spec if not entered at command line
     */
    if (argc < 2)
    {
	    printf ("Please enter file specification (e.g. *.c): ");
	    scanf  ("%35s", dirname);
    }
    else
    {
	    strncpy (dirname, argv[1], MAXLEN);
    }

    /*
     * Use Windows-specific function to find first file matching pathspec
     */
    hFindFile = FindFirstFile (dirname, &finfo);

    if (hFindFile != INVALID_HANDLE_VALUE)
	{
       bResult = TRUE;
	}
	else
	{
		bResult = FALSE;
	}
    while (bResult)
    {
	    count++;	/* Another file detected... */
	    printf ("\n%-13s:", finfo.cFileName);

	   /*
	    * Print out attributes of latest file
	    */
	    printf ("%c%c%c",
		     (finfo.dwFileAttributes & FILE_ATTRIBUTE_READONLY) ? 'R' : ' ',
		     (finfo.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN) ? 'H' : ' ',
		     (finfo.dwFileAttributes & FILE_ATTRIBUTE_SYSTEM) ? 'S' : ' '	);

    	/*
	    * Use Windows-specific function to find first next file
	    */
	    bResult = FindNextFile (hFindFile, &finfo);
    }

    /*
     * Tidy up...
     */
    FindClose (hFindFile);
    printf ("\n%d File(s) detected\n", count);

    return 0;
}
