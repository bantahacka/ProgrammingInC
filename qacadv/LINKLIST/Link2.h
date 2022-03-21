/* Link2.h */

#ifndef _LINK2_INCLUDED
#define _LINK2_INCLUDED

#define MAX_PHONE 16

typedef struct node
{
   struct node * pNext;
   char * pszName;
   char   szPhone [MAX_PHONE+1];
} Node;


#endif /* _LINK2_INCLUDED */