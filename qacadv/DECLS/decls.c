/*********************************************************************
 *                                                                   
 *   Filename:     DECLS.C
 *   Directory:    DECLS
 *
 *   Description:  Solutions to the practical on C declarations.
 *                 Run the code for the answers.
 *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>

void question1(void);
void question2(void);
void question3(void);
void question4(void);
void pause(void);


int main(void)
{
	question1();
	question2();
	question3();
	question4();

	return 0;
}


void question1(void)
{
	/* 1. Describe the types of the following:
	 *
	 *	int	  *a;
	 *	int	  *b[5];
	 *	int	  (*c)[5];
	 *	float d(void);
	 *	float *e(void);
	 *	float (*f)(void);
	 *	float *(*g)(void);
	 *	float (**h)(void);
	 *	char  (*i(void))[3];
	 *	char  *(*j(void))[3];
	 */
	printf("\n\n*** Question 1 ***\n");
	printf("a:\tpointer to an int\n");
	printf("b:\tarray of 5 pointers to int\n");
	printf("c:\tpointer to an array of 5 int\n");
	printf("d:\tfunction (taking no parameters) returning a float\n");
	printf("e:\tfunction (taking no parameters) returning a "
		"pointer to a float\n");
	printf("f:\tpointer to a function (taking no parameters) "
		"returning a float\n");
	printf("g:\tpointer to a function (taking no parameters) "
		"returning a pointer to \n\ta float\n");
	printf("h:\tpointer to a pointer to a function (taking no "
		"parameters) returning\n\ta float\n");
	printf("i:\tfunction (taking no parameters) returning a pointer to an "
		"array\n\tof 3 char\n");
	printf("j:\tfunction (taking no parameters) returning a pointer to an "
		"array\n\tof 3 pointer to char\n");

	pause();
}

void question2(void)
{
	/* 2. Describe the cast and the typedef
	 *    (int (*) (int*))
	 *    typedef void (*PFVV) (void);
	 */
	printf("\n*** Question 2 ***\n\n");
	printf("'(int (*) (int*))' will convert data item into a :-\n"
	       "\tpointer to a function which takes a pointer to an int\n"
	       "\tand returns an int\n\n");
	printf("'PFVV' is a typedef for a pointer to a function taking\n"
	       "\tno arguments and returning nothing\n");
	printf("\tthus 'z' would be declared to have this type\n\n");

	pause();
}


void question3(void)
{
	/* 3. Write declarations for the following:
	 *
	 *	k:	an array of 6 pointers to char
	 *	l:	a pointer to an array of 6 pointer to char
	 *	m:	an array of 5 pointers to arrays of 6 pointers to char
	 *	n:	a function, taking no parameters, returning a pointer
	 *		to char
	 *	o:	a function, taking no parameters, returning a pointer
	 *		to an array of 6 pointer to char
	 *	p:	a function, taking no parameters, returning a pointer
	 *		to a function, taking no parameters, returning an int
	 *	q:	a function, taking no parameters, returning a pointer
	 *		to a function, taking no parameters, returning a
	 *		pointer to an int
	 *	r:	a function, taking no parameters, returning a pointer
	 * 		to a function, taking no parameters, returning a
	 *		pointer to an array of 6 pointer to char
	 *	
	 */
	printf("\n*** Question 3 ***\n\n");
	printf("char *k[6];\n");
	printf("char *(*l)[6];\n");
	printf("char *(*m[5])[6];\n");
	printf("char *n(void);\n");
	printf("char *(*o(void))[6];\n");
	printf("int  (*p(void))(void);\n");
	printf("int  *(*q(void))(void);\n");
	printf("char *(*(*r(void))(void))[6];\n");

	pause();
}


void question4(void)
{
	
	/* 4. Create a typedef such that the "l" above may be declared
	 *    as follows:
	 *
	 *			PA6PC	l;
	 *
	 *    Use this typedef of PA6C to simplify the declarations of
	 *    "m", "o" and "r"
	 *
	 *    Even using this typedef, the declaration of "r" is still
	 *    difficult to read. Create another intermediate typedef 
	 *    to make the declaration easier.
	 */
	printf("\n*** Question 4 ***\n\n");
	printf("typedef char * (*PA6PC)[6];\n\n");
	printf("PA6PC l;\n");
	printf("PA6PC m[5];\n");
	printf("PA6PC o(void);\n");
	printf("PA6PC (*r(void))(void);\n\n");
	printf("typedef PA6PC (*PTF)(void);\n");
	printf("PTF r(void);\n");
	printf("\n\n");
}

void pause(void)
{
	int inkey;
    
	printf("\nPress Enter to continue or q followed by Enter to quit\t");
	fflush(stdin);
	inkey = getchar();
	if(inkey == 'q' || inkey == 'Q')
		exit(0);
	fflush(stdin);
	
	/* Clear the screen. A bit crude, but portable
	 */
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
}
