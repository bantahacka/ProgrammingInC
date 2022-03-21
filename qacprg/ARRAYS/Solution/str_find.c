/************************************************************************
 *                                                                      *
 *   str_find.c   Arrays - Qu. 7 (Optional) Model Solution              *
 *                                                                      *
 *      The output should be five OK's                                  *  
 ***********************************************************************/

#include <stdio.h>

int str_find(char [], char []);

int main(void)
{
    printf("1: %s\n", str_find("abcdef", "xyz") == -1 ? "OK" : "FAIL");
    printf("2: %s\n", str_find("abcdef", "abc") == 0  ? "OK" : "FAIL");
    printf("3: %s\n", str_find("bcbcef", "bce") == 2  ? "OK" : "FAIL");
    printf("4: %s\n", str_find("abcdef", "def") == 3  ? "OK" : "FAIL");
    printf("5: %s\n", str_find("abcdef", "efg") == -1 ? "OK" : "FAIL");

    return 0;
}


int str_find(char s[], char p[])
{
    int i, j;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = 0; s[i+j] == p[j] && p[j] != '\0'; j++)
            ;       /* Null statement */

        if (p[j] == '\0')
            return i;
    }
            
    return -1;  
}

