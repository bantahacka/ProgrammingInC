/************************************************************************
 *                                                                      *
 *   person2.c   Structures - Qu. 2 Model Solution                      *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

/* Structure templates */

struct Date
{
    int d;
    int m;
    int y;
};

struct Person
{
    char         name[31];
    struct Date  birth_date; 
    char         sex;
};

int main(void)
{
    struct Person me = { "Albert Einstein", {12, 2, 1869}, 'M' };
    
    printf("name: %s\n",       me.name);

    printf("born: %d/%d/%d\n", me.birth_date.d,
                               me.birth_date.m,
                               me.birth_date.y);

    printf("sex:  %c\n",       me.sex);

    return 0;
}

