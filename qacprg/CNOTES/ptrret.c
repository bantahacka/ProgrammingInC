/* Pointers and Functions - Functions Returning Pointers */

#include <stdio.h>

int *biggest_element (int [], int) ;
void print_array(int [], int);

int main(void)
{
	int marks[5] = {7, 8, 6, 9, 3} ;
	int *b ;
	b = biggest_element(marks, 5) ;
	*b = 0 ;                         /*  Set the biggest mark to zero */
	print_array(marks, 5);           /*  Print them out */

	return 0;
}

int *biggest_element(int a[], int size)
{
	int *cb ;  /*current biggest */
	int i ;

	cb = &a[0] ;
	for(i = 1;  i < size;  i++)
		if ( *cb < a[i] )
			cb = &a[i];
	return cb ;
}

void print_array(int a[], int size)
{
    int i;

    for(i = 0; i < size; i++)
    	printf("%d ", a[i]);

    printf("\n");
}
