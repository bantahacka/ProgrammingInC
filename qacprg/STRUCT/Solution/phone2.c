/************************************************************************
 *                                                                      *
 *   phone2.c   Structures - Qu. 4 (Optional) Model Solution            *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>
#include <string.h>     /* for strcmp standard function */

struct PhoneNum
{
    int     area;
    char    num[21];
    char    name[21];   
};

/* Function prototypes */
    
void print_entry(int, struct PhoneNum []);
int  find_entry(char [], struct PhoneNum [], int);
int  enter_data(char []);


int main(void)
{
    struct PhoneNum friends[5] =                /* a local array of */
    {                                           /* struct PhoneNum  */
        {171,  "371 6657", "Mike"},             /* initialised too  */
        {171,  "983 4537", "Jo"},
        {1285, "655888",   "QA"},
        {1342, "123 4567", "Mary"},
        {1462, "947 1904", "Q.E.2"}
    };
    
    int  index;
    char who[21];

    int size = sizeof(friends)/sizeof(friends[0]); /* maintainable! */

    while(enter_data(who))
    {
        if ((index = find_entry(who, friends, size)) == -1)
            printf("Don't know number for %s\n", who);
        else
            print_entry(index, friends);
    }

    return 0;
}


/* returns true (1) if valid data was entered otherwise false (0) */

int enter_data(char s[])
{
    do
        printf("Who (type \"stop\" to finish): ");
    while (scanf("%20s", s) != 1);

    return strcmp(s, "stop") == 0 ? 0 : 1;
}


void print_entry(int index, struct PhoneNum pn[])
{
    printf("(0%d) %s\n", pn[index].area, pn[index].num);
}


int find_entry(char a[], struct PhoneNum pn[], int size)
{
    int i;
    int found = 0;

    for(i = 0; i < size && !found; i++)
        if (strcmp(a, pn[i].name) == 0)
            found = 1;

    return found ? i - 1 : -1;
}


