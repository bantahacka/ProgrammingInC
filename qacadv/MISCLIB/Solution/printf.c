/*********************************************************************
 *                                                                   
 *  Filename:     PRINTF.C
 *  Directory:    MISCLIB\SOLUTION
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

    pf("integer i: $i\nlong integer l: $I\n", i, l);
    pf("float f: $f\ndouble d: $d\n", f, d);
    pf("char c: '$c'\nstring s: \"$s\"\n", c, s);

    pf("$i $s $i\n", 1, "through", 28);
    pf("$i $s = $c$d$c\n", 95, "point eight", '[', 95.8, ']');

    return 0;
}


void pf(const char* format, ...)
{
    va_list stackPointer;
    char    ch;

    va_start(stackPointer, format);

    while((ch = *format++) != '\0')
    {
        if(ch != '$')
        {
            putchar(ch);
            continue;
        }

        switch(ch = *format++)
        {
            case 'i':
                /* Cheat by calling the real printf
                 */
                printf("%d", va_arg(stackPointer, int));
                break;
	   
            case 'I':
		        /* Cheat by calling the real printf
                 */
                printf("%ld", va_arg(stackPointer, long int));
                break;
	   
            case 'c':
                /* Notice that as with $i we still pull an integer off
                 * the stack. This is because characters are pushed onto
                 * the stack as integers.
                 */
                putchar(va_arg(stackPointer, int));
                break;
	   
            case 's':
                fputs(va_arg(stackPointer, char*), stdout);
                break;
	   
            case 'f':
            case 'd':
                /* Notice we remove a double from the stack whichever of 'f'
                 * or 'd' is used. This is because floats are pushed onto
                 * the stack as doubles.
		         */
                printf("%f", va_arg(stackPointer, double));
                break;
        }
    }
}
