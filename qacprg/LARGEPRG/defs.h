/*  The header file defs.h                           */

/*  defs.h is the header file used for the program   */   
 
#define  NO         0
#define  STRLEN     80
#define  NEWLINE    '\n'
#define  SPACE      ' '
#define  TAB        '\t'

extern char string[STRLEN + 1];

/*
 * Function prototypes:
 */

void getstring (char *buff);       /* Get string from user         */
void sort      (char word[]);      /* Sort string alphabetically   */
int  search    (char ch,           /* Search for particular char   */
                char word[]);
int  display   (int position,
                char c,
                char word[]);      /* Display the result of search */


/******          END  OF  HEADER  FILE         *******/ 
 
