#if DEBUG
	#define CHECK(A)                \
	{       if(!(A))                \
			printf(#A "\tfailed %s, %d ", __FILE__,  __LINE__ ); }
#else
	#define CHECK(A)
#endif
