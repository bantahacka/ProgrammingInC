/*********************************************************************
 *                                                                   
 *  Filename:     DISP_DB.C
 *  Directory:    STRUCT\SOLUTION
 *
 *  Description:  This program reads element records from a binary  
 *                data file and displays each record on the screen.
 * 
 *********************************************************************/

#include <stdio.h>
#include <string.h>

#include "elem.h"          /* Uses NEWELEMENTDATA struct template */

int  Display (char fname[]);

int  ReadBinaryRec (FILE *fpout, NEWELEMENTDATA *pRec);
void DispBinaryRec (NEWELEMENTDATA *pRec);

int main(void)
{
    char in_fname [80+1];               /* Name of input file */
    int  result;                        /* Result of Build()   */

    printf("Name of input (binary) file:  ");
    scanf("%s", in_fname);
    
    result = Display(in_fname);
    return result;
}
                        
                        
/* 
 *  Display() is a high-level function to open the input file, and 
 *  co-ordinate the main loop to read records from the text file and 
 *  display the data on the screen.
 */

int Display (char in_fname[])
{
    FILE  *fpin;                        /* Handle for input file     */
    
    NEWELEMENTDATA  current;            /* Buffer to read recs into  */ 
            

    fpin = fopen(in_fname, "rb");       /* Open input (binary) file  */
    if (fpin == NULL)
    {
        fprintf(stderr, "Failed to open %s for reading\n",  in_fname);
        return 0;
    }

    while (ReadBinaryRec(fpin, &current) != EOF)
    {    
        DispBinaryRec(&current);
    }

    fclose(fpin);
    return 1;
}
                                                                    
                                                                    
/* 
 *  ReadBinaryRec() reads one record from the input file into "prec".
 *  Return EOF if end of file is found.
 */

int ReadBinaryRec (FILE *fpin, NEWELEMENTDATA *prec)
{
    static  int recordNum;

    recordNum++;

    if (1 != fread(prec, sizeof(*prec), 1, fpin))
    {
        fprintf(stderr, "bad read on record %d\n", recordNum);
        return EOF;
    }

    return 1;
}


/* 
 *  DispBinaryRec() displays the data in the binary "prec".
 */

void DispBinaryRec (NEWELEMENTDATA *prec)
{
    printf("\nElement name:         %c%c\n",       prec->name[0], 
                                                   prec->name[1]);

    printf("Rel. molecular mass:  %.2f\n",         prec->rmm);
    printf("Melting point:        %.2f Kelvin\n",  prec->mp);
    printf("Boiling point:        %.2f Kelvin\n",  prec->bp);
    
    if (prec->bcc)       printf ("Block-Centred-Cubic  ");     
    if (prec->cubic)     printf ("Cubic  ");     
    if (prec->fcc)       printf ("Face-Centred-Cubic  ");     
    if (prec->hcp)       printf ("Hexagonal-Close-Packed  ");     
    if (prec->mon)       printf ("Monoclinic  ");     
    if (prec->ortho)     printf ("Orthorhombic  ");     
    if (prec->rhombic)   printf ("Rhombic  ");     
    if (prec->tetra)     printf ("Tetrahedral  ");     
    if (prec->hex)       printf ("Hexagonal-Planar  ");     
    
    printf("\n");        /* Tidy up ready for next record ... */
}
