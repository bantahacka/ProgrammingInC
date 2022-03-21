/************************************************************************
 *                                                                      *
 *  tdef2.h Further Data Types - Qu. 2 Header file for Model Solution 2 *
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

void Pscanf(const char *, POINT *);

void Pprintf(const char *, POINT *);


