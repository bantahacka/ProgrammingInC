#ifndef CCALC_FUNCSDEF_H
#define CCALC_FUNCSDEF_H
/* Functions:
 * Each of the functions will take either 1 or 2 numbers as floats, and a pointer to the result variable which is also a float
 */

// General functions
void printhelp();
void printmenu();
float entersingle();
float enterfirst();
float entersecond();
float enterpwr();


// Basic math functions
void addition(float, float, float *);
void subtraction(float, float, float *);
void multiplier(float, float, float *);
void divider(float, float, float *);
void pct(float, float, float *);

// Power functions
void topower(float, float, float *);
void sqroot(float, float *);
void curt(float, float *);

// Memory functions
void add_to_mem(float *, float *);
void ret_from_mem(float *, float *);
void mem_clear(float *);
#endif //CCALC_FUNCSDEF_H
