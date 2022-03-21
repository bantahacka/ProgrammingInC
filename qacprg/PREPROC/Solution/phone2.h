/************************************************************************
 *                                                                      *
 *   phone2.h Preprocessor - Qu. 2 (Optional) Header file for           *
 *                                              Model Solution          *
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

#define CASTLE    1
#define ROSEBERY  2
#define BARTON    3

#define SITE CASTLE

#if SITE == CASTLE
    #define QA {1285, "655888", "QA"}

#elif SITE == ROSEBERY
    #define QA {171, "713 7639", "QA"}

#elif SITE == BARTON
    #define QA {1285, "641052", "QA"}

#else
    #define QA {0, "192", "Directory Enquiry"}

#endif
