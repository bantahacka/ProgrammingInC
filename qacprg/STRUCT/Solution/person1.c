/************************************************************************
 *                                                                      *
 *   person1.c Structures - Qu. 1 Model Solution                        *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* This defines struct Person. It is a "template" which defines the members */
/* of struct Person. It does not reserve space or create any variables      */

struct Person
{
    char name[31];    /* 30 characters plus one extra for '\0' terminator */
    int  age;
    char sex;         /* 'M' or 'F' */
};


int main(void)
{
    struct Person me = { "Albert Einstein", 110, 'M' };   /* local */
    
    me.age++;
    printf("name:\t%s\n", me.name);
    printf("age:\t%d\n",  me.age);
    printf("sex:\t%c\n",  me.sex);

    return 0;
}
