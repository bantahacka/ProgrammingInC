#include <stdio.h>

typedef int METRES;
#define MSIZE 10


METRES get_max(METRES *, int);

void m_init(METRES *, int);

void m_print(METRES);

int main(void)
{
	METRES heights[MSIZE];
	METRES x;


	int i = 0;
	for(i = 0; i<MSIZE; i++)
	{
		m_init(&heights[i], MSIZE - i);
	}

	for(i = 0; i<MSIZE; i++)
	{
		m_print(heights[i]);
		printf("\n");
	}



	x = get_max(heights, MSIZE);

	m_print(x);
	printf("\n");

	return 0;
}


/* Function definitions - would be in a library */


void m_init(METRES *m, int value)
{
	*m = (METRES)value;
}

void m_print(METRES m)
{
	printf("%d", (int)m);
}

METRES get_max(METRES *mp, int size)
{
	int cb ;  /*current biggest */
	int i ;

	cb = (int)mp[0];
	for(i = 1;  i < size;  i++)
		if ( cb < (int)mp[i] )
			cb = (int)mp[i];
	return (METRES)cb ;

}

