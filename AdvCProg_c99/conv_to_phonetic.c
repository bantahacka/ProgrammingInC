#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void convert_string(char *, char *);
// enum alphabet {a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z};
char alphabet_lookup[26][9] = {"Alpha","Bravo","Charlie","Delta", "Echo", "Foxtrot", "Golf", "Hotel", "India", "Juliet",
                               "Kilo","Lima","Mike","November","Oscar","Papa","Quebec","Romeo","Sierra","Tango",
                               "Uniform","Victor","Whiskey","Xray","Yankee","Zulu" };
int main()
{

    char input_arr[255];
    char temp_text[2295];
    int ilen;
    printf("Enter a phrase (Max 255 chars): ");
    fgets(input_arr,255,stdin);
    ilen = strlen(input_arr);
    if(input_arr[ilen-1] =='\n')
    {
        input_arr[ilen-1] = '\0';
    }
    convert_string(input_arr, temp_text);
    return 0;
}

void convert_string(char *user_input, char *phonetic_text)
{
    int pos = 0;
    int pos2 = 0;
    int wordlen;
    char space[2] = " ";
    char lookup[12];
    char ch;
    while(user_input[pos] != '\0')
    {
        if(isalpha(user_input[pos]))
        {
            ch = toupper(user_input[pos]);
            strcpy(lookup, alphabet_lookup[ch - 65]);
            strcat(lookup, space); // Look at strncpy, or sprintf
            strcpy(&phonetic_text[pos2], lookup);
            wordlen = strlen(lookup);
            pos2 += wordlen;
        }
        pos++;
    }
    printf("Phonetic: %s", phonetic_text);
};