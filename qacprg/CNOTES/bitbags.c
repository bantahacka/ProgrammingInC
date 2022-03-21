/* bit manipulation */

#include <stdio.h>

int main(void)
{
	unsigned int bitbag = 99 ;
	unsigned int w, x, y, z ;
	unsigned int shl, shr ;

	w = bitbag & 6 ;
	x = bitbag | 6 ;
	y = bitbag ^ 6 ;
	z = ~bitbag ;

	shl = bitbag << 1 ;
	shr = bitbag >> 1 ;

	printf("bitbag = %x, w = %x, x = %x, y = %x, z = %x\n"
	       "shl = %x and shr = %x\n", bitbag, w,x,y,z,shl,shr);

	return 0;
}
