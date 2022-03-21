/*********************************************************************
 *                                                                   
 *  Filename:     MAKE_DB.C
 *  Directory:    STRUCT
 *
 *  Description:  This is a utility program to read data from a text
 *                file and write it out as records to a binary file.
 *
 *********************************************************************/

#include <stdio.h>
#include <string.h>
#include "elem.h"               /* Holds ELEMENTDATA struct template */


int   ReadTextualRec (FILE *fpin,  ELEMENTDATA *pRec);
int   WriteBinaryRec (FILE *fpout, ELEMENTDATA *pRec);

void  Build();
void  Query();

void  ScanFlags (char *flags, ELEMENTDATA *pRec);


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
 *  Fill in this function, to display the "sizeof" the element struct
 */

void Query()
{


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
    
    ELEMENTDATA  current;               /* Buffer to read recs into  */ 
            
    
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

int ReadTextualRec (FILE *fpin, ELEMENTDATA *prec)
{
    int        c;
    int        items;
    char       name[3] = {0};
    char       arrange[10];
    double     rmm;
    double     melt;
    double     boil;
    static int number;


    memset(prec, 0, sizeof(*prec));   /* Clear contents of input rec */
    
    for(;;)                           /* Skip any comment line       */
    {
        number++;
    
        if((c = fgetc(fpin)) == '#') 
        {
            while((c = fgetc(fpin)) != '\n')
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

    items = fscanf(fpin, "%[^/]/%lf/", name, &rmm);
    if(items != 2)
    {
        if(items != EOF)
            fprintf(stderr, "line %d, bad read\n", number);

        return EOF;
    }

    c = fgetc(fpin);        /* Get the atomic arrangement settings */
    if(c == '/')
    {
        arrange[0] = '\0';  /* element has unknown structure */
    }
    else
    {
        ungetc(c, fpin);
        if(fscanf(fpin, "%[^/]/", arrange) != 1) 
        {
            fprintf(stderr, "line %d (element %s), bad read\n", number, name);
            return EOF;
        }
    }

    if(2 != fscanf(fpin, "%lf/%lf\n", &melt, &boil)) 
    {
        if(items != EOF)
            fprintf(stderr, "line %d (element %s), bad read\n", number, name);

        return EOF;
    }

    prec->first  = name[0];
    prec->second = name[1];
    prec->rmm    = rmm;
    prec->mp     = melt;
    prec->bp     = boil;

    ScanFlags(arrange, prec);

    return 1;
}


/* 
 *  ScanFlags() scans the characters in the "arrangeflags" string. 
 *  Valid atomic arrangements are:
 *    b, c, f, h, m, o, r, t, x
 */
void ScanFlags (char *arrangeflags, ELEMENTDATA *prec)
{
    prec->bcc      = 'n';
    prec->cubic    = 'n';
    prec->fcc      = 'n';
    prec->hcp      = 'n';
    prec->mon      = 'n';
    prec->ortho    = 'n';
    prec->rhombic  = 'n';
    prec->tetra    = 'n';
    prec->hex      = 'n';

    while(*arrangeflags != '\0')
    {
        switch(*arrangeflags)
        {
            case 'b':    prec->bcc     = 'y';    break;
            case 'c':    prec->cubic   = 'y';    break;
            case 'f':    prec->fcc     = 'y';    break;
            case 'h':    prec->hcp     = 'y';    break;
            case 'm':    prec->mon     = 'y';    break;
            case 'o':    prec->ortho   = 'y';    break;
            case 'r':    prec->rhombic = 'y';    break;
            case 't':    prec->tetra   = 'y';    break;
            case 'x':    prec->hex     = 'y';    break;
        }
        arrangeflags++;
    }
}


/* 
 *  WriteBinaryRec() takes an ELEMENTDATA structure and writes it to 
 *  the specified output file in binary format.
 */

int WriteBinaryRec (FILE *fpout, ELEMENTDATA *prec)
{
    static  int recordNum;

    recordNum++;

    if(1 != fwrite(prec, sizeof(*prec), 1, fpout))
    {
        fprintf(stderr, "bad write on record %d\n", recordNum);
        return EOF;
    }

    return 1;
}



