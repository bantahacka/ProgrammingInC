/************************************************************************
 *                                                                      *
 *   phone1.c Preprocessor - Qu. 1 Model Solution                       *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include "phone1.h"

int main(void)
{
    struct PhoneNum friends[FRIENDS] =          /* a local array of */
    {                                           /* struct PhoneNum  */
        {171,  "371 6657", "Mike"},             /* initialised too  */
        {171,  "983 4537", "Jo"},
        {1285, "655888",   "QA"},
        {1342, "123 4567", "Mary"},
        {1462, "947 1904", "Q.E.2"}
    };
    
    int i;

    for(i = 0; i < FRIENDS; i++)
        printf("%s\t-\t(0%d) %s\n", friends[i].name,
                    friends[i].area,
                    friends[i].num);

    return 0;
}

