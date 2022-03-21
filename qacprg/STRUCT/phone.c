/************************************************************************
 *                                                                      *
 *   phone.c   Structures - Qu. 3 Code Template                         *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

struct PhoneNum
{
    int     area;       /* area code */
    char    num[21];    /* phone number */
    char    name[21];   /* name of person */
};

int main (void)
{
    struct PhoneNum friends[5] =                /* a local array of */
    {                                           /* struct PhoneNum  */
        {171,  "371 6657", "Mike"},             /* initialised too  */
        {171,  "983 4537", "Jo"},
        {1285, "655888",   "QA"},
        {1342, "123 4567", "Mary"},
        {1462, "947 1904", "Q.E.2"}
    };

/* UP TO YOU!! */

    return 0;
}
