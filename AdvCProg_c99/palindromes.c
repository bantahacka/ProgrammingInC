#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <strings.h>

void strip_chars(char *, char *);
void check_reverse(char *, char *);

int main()
{
    char user_input[255];
    char temp_text[255];
    int i=0;
    printf("Enter a string to check if it is a palindrome: ");
    fgets(user_input, 255, stdin);
    i = strlen(user_input);
    if(user_input[i-1] =='\n')
    {
        user_input[i-1] = '\0';
    }
    strcpy(temp_text, user_input);
    strip_chars(user_input, temp_text);
    check_reverse(user_input, temp_text);
    return 0;
}

void strip_chars(char *user_input, char *temp_text)
{
    int i = 0;
    int j = 0;
    char ch;
    while(user_input[i] != '\0')
    {
        if(isalpha(user_input[i]))
        {
            ch = user_input[i];
            if(isupper(ch))
            {
                ch = ch + 32;
            }
            strcpy(&temp_text[j], &ch);
            j++;
        }
        i++;
    }
    temp_text[j] = '\0';
}

void check_reverse(char *user_input, char *temp_text)
{
    int i = 0;
    char temp_rev[255];
    for(i;i<strlen(temp_text);i++)
    {
        temp_rev[i] = temp_text[strlen(temp_text) -i - 1];
    }
    if(strcmp(temp_text, temp_rev) == 0)
    {
        printf("\n%s is a palindrome!", user_input);
    }
    else
    {
        printf("\n%s is not a palindrome.", user_input);
    }
}