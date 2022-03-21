/*********************************************************************
 *
 *  Filename:     BSEARCH.C
 *  Directory:    SORTSRCH
 *
 *  Description:  A program to use bsearch() to check if values are present
 *                or absent from an array of integers
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	ASIZE(A)	(sizeof(A)/sizeof(A[0]))

int	compInt(const int* first, const int* second);
int	lookFor(int a[], int look, int howMany);

int main(void)
{
    int a[] = {
	  881,  716,  750,  707,  152,  733,  739,  492,  923,  946,
	  709,  419,  492,   18,   16,  556,  153,  537,  758,  602,
	  985,  926,  562,  245,  459,  616,  210,  516,  177,  476,
	  154,  132,  254,  450,   71,   57,  179,  994,  353,  684,
	  760,  193,  308,  175,  665,  840,  560,  797,  246,  126,
	  608,  221,  872,   77,  161,  656,  113,   67,   68,  488,
	  868,  778,   77,   92,  245,  873,  836,  753,  737,  420,
	  796,  172,  593,  506,   74,   77,  507,  230,  352,  742,
	  882,  425,   19,  701,  223,  853,   82,  213,  919,  141,
	  832,  108,  439,  499,  100,  832,  566,  577,  926,  275,
	  114,  733,  333,  817,  790,  207,  399,  232,  826,  348,
	  800,  359,  811,  440,  855,  266,   93,  120,   69,  717,
	  438,  958,  103,  839,   84,  560,  190,  873,  170,  219,
	  262,  822,  599,   99,  883,  358,   32,  215,  483,  534,
	  895,  339,  663,  794,   27,  781,  555,  397,  698,  420,
	  145,  376,  237,  238,  145,    9,  155,   98,  133,  214,
	  160,   53,  729,  923,  871,  440,  952,  472,  310,  281,
	  261,  135,  681,  329,  591,  828,  138,  119,  225,  598,
	  415,  211,  296,   37,  428,  765,   30,  132,  699,  927,
	  671,  192,  649,  472,  722,  594,  770,  587,  394,  714
    };
    
    /* SORT THE ARRAY AS BEFORE */

    

    /* Look for various numbers we know are in the array */
    
    if(lookFor(a, a[67], ASIZE(a)) == 67)
        printf("Correctly found %d\n", a[67]);
    else
        printf("FAILED to find %d at location 67 in array\n", a[67]);

    if(lookFor(a, a[100], ASIZE(a)) == 100)
        printf("Correctly found %d\n", a[100]);
    else
        printf("FAILED to find %d at location 100 in array\n", a[100]);

    if(lookFor(a, a[158], ASIZE(a)) == 158)
        printf("Correctly found %d\n", a[158]);
    else
        printf("FAILED to find %d at location 158 in array\n", a[158]);

    if(lookFor(a, -100, ASIZE(a)) == -1)
        printf("Correctly didn't find -100\n");
    else
        printf("FAILED to tell that -100 wasn't in the array\n");

    if(lookFor(a, 10000, ASIZE(a)) == -1)
        printf("Correctly didn't find 10000\n");
    else
        printf("FAILED to tell that 10000 wasn't in the array\n");

    return 0;
}
