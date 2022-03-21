/************************************************************************
 *                                                                      *
 *   phone1.h Preprocessor - Qu. 1 Header file for Model Solution       *
 *                                                                      *
 ************************************************************************/

#define NUMSIZE 20
#define NAMESIZE 20
#define FRIENDS 5

struct PhoneNum
{
    int     area;
    char    num[NUMSIZE + 1];
    char    name[NAMESIZE + 1];
};


