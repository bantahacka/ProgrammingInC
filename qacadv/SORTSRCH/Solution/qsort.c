/*********************************************************************
 *
 *  Filename:     QSORT.C
 *  Directory:    SORTSRCH\SOLUTION
 *
 *  Description:  This program uses the standard qsort function to
 *                sort an array of integers.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define	ASIZE(A)	(sizeof(A)/sizeof(A[0]))

void checkArrayIsSorted(int a[], int elements);
int  compInt(const int* first, const int* second);


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
    
    qsort(a, ASIZE(a), sizeof(int), compInt);
    
    checkArrayIsSorted(a, ASIZE(a));

    return 0;
}

int	compInt(const int * first, const int * second)
{
    return *first - *second;
}

void checkArrayIsSorted(int a[], int elements)
{
    int i = 0;

    for(i = 0; i < elements - 1; i++)
    {
        if(a[i] > a[i + 1])
        {
            printf("the array is NOT sorted\n");
            return;
        }
    }
    
    printf("the array is sorted properly\n");
}
