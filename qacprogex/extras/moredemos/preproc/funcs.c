#include "defs.h"
void operators()
{
	printf(MAKE_STR(x>0) " failed at %d in %s\n", __LINE__, __FILE__);
	printf(JOIN(GOOD, BYE) "\n");
}