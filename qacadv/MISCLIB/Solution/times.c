/*********************************************************************
 *
 *  Filename:     TIMES.C
 *  Directory:    MISCLIB\SOLUTION
 *
 *  Description:  This program calculates the upper and lower limits for
 *                a specific implementation of the standard library
 *                time calculations. That is to say, everyone uses a
 *                value representing the number of seconds past a given date
 *                and time. However the "given date and time" vary. This
 *                program finds out what this date and time is. Also, because
 *                the number has a fixed size, it has a fixed maximum. Thus
 *                there is some date beyond which representation will cause
 *                overflow and error. This date is calculated too.
 *
 *********************************************************************/

#include <time.h>
#include <stdio.h>
#include <sys\types.h>
#include <sys\timeb.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>


#define NICE_TIME   " at %H:%M %A, %B %d %Y"

int main(void)
{
    char        buf[128];
    time_t      beginning;
    time_t      end;
    struct tm*  t;

    /* Comment out these two lines and the local times and UTC
     * times printed out below will differ
     */
    if(getenv("TZ") == NULL)
        _putenv("TZ=GMT0BST");
    
    /* Set time zone from TZ environment variable. If TZ is not set,
     * PST8PDT is used (Pacific standard time, daylight savings).
     */
    _tzset();

    beginning = 0;
    end       = LONG_MAX;
    
    t = gmtime(&beginning);
    strftime(buf, sizeof(buf), "Time began" NICE_TIME, t);
    printf("%s\n", buf);


    t = localtime(&beginning);
    strftime(buf, sizeof(buf), "Local time began" NICE_TIME, t);
    printf("%s\n", buf);


    t = gmtime(&end);
    strftime(buf, sizeof(buf), "Time will end" NICE_TIME, t);
    printf("%s\n", buf);


    t = localtime(&end);
    strftime(buf, sizeof(buf), "Local time will end" NICE_TIME, t);
    printf("%s\n", buf);

    return 0;
}        
