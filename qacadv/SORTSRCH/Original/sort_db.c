/*********************************************************************
 *
 *  Filename:     SORT_DB.C
 *  Directory:    SORTSRCH
 *
 *  Description:  This program reads element records from a binary 
 *                data file and displays each record on the screen. 
 *
 *
 *********************************************************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#include "elem.h"

#define N_ELEMENTS  90

void readIn(char* in_fname, NEWELEMENTDATA* elements, int size);
void displayRecords(char* grandTitle, NEWELEMENTDATA** elements, int size); 




void main(int argc, char* argv[])
{
    int             i;
    char            in_fname[80+1];               /* Name of input file */ 
    NEWELEMENTDATA  elements[N_ELEMENTS];

    NEWELEMENTDATA* nameOrder[N_ELEMENTS];
    NEWELEMENTDATA* rmmOrder [N_ELEMENTS];
    NEWELEMENTDATA* meltOrder[N_ELEMENTS];



    if(argc > 1)
    {
        strcpy(in_fname, argv[1]);
    }
    else
    {
        printf("Name of input (binary) file:  "); 
        scanf("%s", in_fname);
    }

    readIn(in_fname, elements, N_ELEMENTS);

    /* Initialise all the pointers in the arrays
     */
    for(i = 0; i < N_ELEMENTS; i++)
        nameOrder[i] = rmmOrder[i] = meltOrder[i] = &elements[i];


    displayRecords("Name Order:",          nameOrder, N_ELEMENTS); 
    displayRecords("Melting Point Order:", meltOrder, N_ELEMENTS); 
    displayRecords("RMM Order:",           rmmOrder,  N_ELEMENTS);
}


void readIn(char* in_fname, NEWELEMENTDATA* elements, int size) 
{
    int   count;
    FILE* stream;

    if((stream = fopen(in_fname, "rb")) == NULL) 
    {
        printf("ERROR: failed to open input file \"%s\", %d, ",
			                            in_fname, errno); 
	    perror("");
        printf("bailing out\n");
        exit(90);
    }

    if((count = fread(elements, sizeof(NEWELEMENTDATA), size, stream)) != size) 
    {
        printf( "ERROR: only read %d elements, "
                "expected to read %d elements\n", count, size);

        printf("bailing out\n");
        exit(99);
    }

    fclose(stream);
}



/* displayRecords() displays the data in the binary "prec".
 */
void displayRecords(char* grandTitle, NEWELEMENTDATA** elements, int size) 
{
    int i;

    printf("AND NOW FOR %s\n\n\n\n", grandTitle);

    printf("press return to start:\n");
    printf("then keep pressing return for more elements, or 'q' to quit "); 
    fflush(stdin);
    getchar();
    printf("\n\n");

    for(i = 0; i < size; i++) 
    {

        printf("\nElement:       %c%c\n",       elements[i]->name[0],
                                                elements[i]->name[1]);

        printf("Rmm:           %.2f\n",         elements[i]->rmm); 
        printf("Melting point: %.2f Kelvin\n",  elements[i]->mp); 
        printf("Boiling point: %.2f Kelvin\n",  elements[i]->bp);

        if (elements[i]->bcc)     printf ("Block-Centred-Cubic  "); 
        if (elements[i]->cubic)   printf ("Cubic  ");
        if (elements[i]->fcc)     printf ("Face-Centred-Cubic  ");
        if (elements[i]->hcp)     printf ("Hexagonal-Close-Packed  "); 
        if (elements[i]->mon)     printf ("Monoclinic  ");
        if (elements[i]->ortho)   printf ("Orthorhombic  "); 
        if (elements[i]->rhombic) printf ("Rhombic  ");
        if (elements[i]->tetra)   printf ("Tetrahedral  ");
        if (elements[i]->hex)     printf ("Hexagonal-Planar  ");

        printf("\n");        /* Tidy up ready for next record ... */

        fflush(stdin);
        if(getchar() == 'q')
            return;
    }
}

