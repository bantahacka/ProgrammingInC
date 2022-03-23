#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int check_for_at(const char [], size_t);

int main()
{
    char user_email[] = "null@null.com";
    int result;
    printf("Enter your email address: ");
    scanf("%s", &user_email);
    size_t len = strlen(user_email);
    result = check_for_at(user_email, len);
    if (result == 0)
    {
        printf("\n%s is valid", user_email);
    }
    else
    {
        printf("\n%s is invalid", user_email);
    }
    return 0;
}

int check_for_at(const char email[], size_t len)
{
    char str1 = '@';
    size_t i;
    for(i=0;i<len;i++)
    {
        if(str1 == email[i] && i>0 && i<len)
        {
            return 0;
        }
        else
        {
            continue;
        }
    }
    return 1;
}
