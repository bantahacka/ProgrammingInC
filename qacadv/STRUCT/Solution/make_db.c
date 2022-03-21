/*********************************************************************
 *                                                                   
 *  Filename:     MAKE_DB.C
 *  Directory:    STRUCT\SOLUTION
 *
 *  Description:  This is a utility program to read data from a text
 *                file and write it out as records to a binary file.
 *
 *                This version uses the revised NEWELEMENTDATA struct
 *                which makes better use of memory than ELEMENTDATA.
 *
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include "elem.h"          /* Uses NEWELEMENTDATA struct template */


int   ReadTextualRec (FILE *fpin,  NEWELEMENTDATA *pRec);
int   WriteBinaryRec (FILE *fpout, NEWELEMENTDATA *pRec);

void  Build();
void  Query();

void  ScanFlags (char *flags,  NEWELEMENTDATA *pRec);


int main(void)
{
    int response;
    
    printf("What option do you require?\n");
    printf(" 1  Build binary file\n");
    printf(" 2  Query struct size\n\n");
    printf("==> ");
    scanf("%d", &response);

    if (response == 1)
        Build();
    else if (response == 2)
        Query();
    else
        printf("\nInvalid response, program terminating\n");

    return 0;
}
                        
                        
/* 
 *  Filled-in function, to display the "sizeof" the element struct
 */

void Query()
{
    printf("Original structure size: %u\n", sizeof(ELEMENTDATA));
    printf("New      structure size: %u\n", sizeof(NEWELEMENTDATA));
}


/* 
 *  Build() is a high-level function to open files, and co-ordinate the 
 *  main loop to read records from the text file and write the corresponding
 *  data to the output file in binary format.
 */

void Build()
{
    char in_fname [80+1];               /* Name of input  file */
    char out_fname[80+1];               /* Name of output file */

    FILE  *fpin;                        /* Handle for input  file    */
    FILE  *fpout;                       /* Handle for output file    */
    
    NEWELEMENTDATA  current;            /* Buffer to read recs into  */ 
            
    
    /* Ask user for filenames */
    printf("Name of input (textual) file:  ");
    scanf("%s", in_fname);
    
    printf("Name of output (binary) file:  ");
    scanf("%s", out_fname);

    
    /* Open the input (text) file */
    fpin = fopen(in_fname, "rt");
    if(fpin == NULL)
    {
        fprintf(stderr, "Failed to open %s for reading\n",  in_fname);
        return;
    }


    /* Open the output (binary) file */
    fpout = fopen(out_fname, "wb");
    if(fpout == NULL)
    {
        fprintf(stderr, "Failed to open %s for writing\n",  out_fname);
        return;
    }


    while(ReadTextualRec(fpin,  &current) != EOF && 
           WriteBinaryRec(fpout, &current) != EOF)
    {    
        ;   /* Null body - WriteBinaryRec() has done it all */
    }


    printf("Done!\n");

    fclose(fpin);
    fclose(fpout);
}
                                                                    
                                                                    
/* 
 *  ReadTextualRec() reads one record (ie a line of text) from input file 
 *  into the "pRec" input buffer. Return EOF if end of file is found.
 */

int ReadTextualRec (FILE *fpin, NEWELEMENTDATA *prec)
{
    int        c;
    int        items;
    char       name[3] = {0};
    char       arrange[10];
    float      rmm;                   /* Used to be double */ 
    float      melt;                  /* Used to be double */ 
    float      boil;                  /* Used to be double */
    static int number;

    memset(prec, 0, sizeof(*prec));   /* Clear contents of input rec */
    
    for (;;)                          /* Skip any comment line       */
    {
        number++;
    
        if ((c = fgetc(fpin)) == '#') 
        {
            while ((c = fgetc(fpin)) != '\n')
                ;   /* Null body - skips over chars until END OF LINE */
        } 
        else
        {
            ungetc(c, fpin);
            break;
        }
    }

    
    /* Get chars up to first '/'  -  this is the element name     */
    /* Then get next double       -  this is the RMM double value */

    items = fscanf(fpin, "%[^/]/%f/", name, &rmm);
    if (items != 2)
    {
        if (items != EOF)
            fprintf(stderr, "line %d, bad read\n", number);

        return EOF;
    }

    c = fgetc(fpin);        /* Get the atomic arrangement settings */
    if (c == '/')
    {
        arrange[0] = '\0';  /* element has unknown structure */
    }
    else
    {
        ungetc(c, fpin);
        if (fscanf(fpin, "%[^/]/", arrange) != 1) 
        {
            fprintf(stderr, "line %d (element %s), bad read\n", number, name);
            return EOF;
        }
    }

    if (2 != fscanf(fpin, "%f/%f\n", &melt, &boil)) 
    {
        if(items != EOF)
            fprintf(stderr, "line %d (element %s), bad read\n", number, name);

        return EOF;
    }

    strcpy(prec->name, name);
    prec->rmm = rmm;
    prec->mp  = melt;
    prec->bp  = boil;

    ScanFlags(arrange, prec);

    return 1;
}


/* 
 *  ScanFlags() scans the characters in the "arrangeflags" string. 
 *  Valid atomic arrangements are:
 *    b, c, f, h, m, o, r, t, x
 */

void ScanFlags (char *arrangeflags, NEWELEMENTDATA *prec)
{
  /*  
   *  Removed the following, because the relevant bitfield in prec
   *  will already have been set to 0 (the default) at the start 
   *  of ReadTextualRec():
   *
   *    prec->bcc      = 'n';    removed this line
   *    prec->cubic    = 'n';    removed this line 
   *    prec->fcc      = 'n';    removed this line 
   *    prec->hcp      = 'n';    removed this line 
   *    prec->mon      = 'n';    removed this line 
   *    prec->ortho    = 'n';    removed this line 
   *    prec->rhombic  = 'n';    removed this line 
   *    prec->tetra    = 'n';    removed this line 
   *    prec->hex      = 'n';    removed this line
   */

    while (*arrangeflags != '\0')
    {
        switch(*arrangeflags)
        {
            case 'b':    prec->bcc     = 1;    break;
            case 'c':    prec->cubic   = 1;    break;
            case 'f':    prec->fcc     = 1;    break;
            case 'h':    prec->hcp     = 1;    break;
            case 'm':    prec->mon     = 1;    break;
            case 'o':    prec->ortho   = 1;    break;
            case 'r':    prec->rhombic = 1;    break;
            case 't':    prec->tetra   = 1;    break;
            case 'x':    prec->hex     = 1;    break;
        }
        arrangeflags++;
    }
}


/* 
 *  WriteBinaryRec() takes an ELEMENTDATA structure and writes it to 
 *  the specified output file in binary format.
 */

int WriteBinaryRec (FILE *fpout, NEWELEMENTDATA *prec)
{
    static  int recordNum;

    recordNum++;

    if (1 != fwrite(prec, sizeof(*prec), 1, fpout))
    {
        fprintf(stderr, "bad write on record %d\n", recordNum);
        return EOF;
    }

    return 1;
}


