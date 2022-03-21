/*********************************************************************
 *                                                                   
 *  Filename:     PRINTF.C
 *  Directory:    MISCLIB
 *
 *  Description:  Template for your much simplified version of printf called
 *                "pf" written to use the variadic macros.
 *
 *                With this version:
 *                      $i prints an int
 *                      $I prints a long
 *                      $f prints a float
 *                      $d prints a double
 *                      $c prints a char
 *                      $s prints a string
 *
 *                You are NOT expected to translate the above to the
 *                corresponding printf sequences and call printf or vprintf.
 *                You're expected to do things using va_start, va_arg etc.
 *
 *********************************************************************/

#include <stdio.h>
#include <stdarg.h>

void pf(const char*, ...);

int main(void)
{
    int     i = 25;
    long    l = 250000;
    float   f = 27.0F;
    double  d = 27.27;
    char    c = 'g';
    char*   s = "string";

    pf("hello world\n");
    pf("integer i: $i\n", i);
    pf("long integer l: $I\n", l);
    pf("float f: $f\n", f);
    pf("double d: $d\n", d);
    pf("char c: '$c'\n", c);
    pf("string s: \"$s\"\n", s);
    pf("$i $s $i\n", 1, "through", 28);
    pf("$i $s = $c$d$c\n", 95, "point eight", '[', 95.8, ']');

    return 0;
}

void pf(const char* format, ...)
{
    /* Walk down the format string until it runs out.
     *
     * By the way, you are NOT expected to change all of the '$' signs
     * to '%' and then call vprintf, you're expected to do things the
     * hard way!! Don't think this would work, because vprintf would
     * not understand $I for long integers (that would need to be "ld")
     */
    char ch;
    
    while((ch = *format++) != '\0')
    {


    }
}
