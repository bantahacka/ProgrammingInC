/************************************************************************
 *                                                                      *
 *   tdef.h Further Data Types - Qu. 2 Prewritten header file           *
 *                                                                      *
 ************************************************************************/

typedef int COORDINATE;
typedef unsigned short COLOUR;

typedef struct Point
{
	COORDINATE x;
	COORDINATE y;
	COLOUR col;
}POINT;


/* Function prototypes */
void Pinitialise(POINT *);
void Pprint(POINT *);


/* Function prototypes for ALTERNATIVE question */
void Pscanf(const char *, POINT *);
void Pprintf(const char *, POINT *);
