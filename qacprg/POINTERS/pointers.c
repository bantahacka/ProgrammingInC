/************************************************************************
 *                                                                      *
 *    pointers.c Build and run this program for the correct answers     *
 *                                                                      *
 ************************************************************************/

#include <stdio.h>

void testa(void);
void testb(void);
void testc(void);
void testd(void);
void teste(void);
void testf(void);
void testg(void);
void testh(void);
void testi(void);
void testj(void);
void testk(void);
void testl(void);
void testm(void);
void testn(void);

int main(void)
{
    printf("ANSWERS ARE:\n");
    testa();
    testb();
    testc();
    testd();
    teste();
    testf();
    testg();
    testh();
    testi();
    testj();
    testk();
    testl();
    testm();
    testn();

    return 0;
}



void    testa()
{
    int m, n;
    int *iptr;

    m = 38;
    iptr = &m;
    n = *iptr;

    printf("a) n = %d\n", n);
}

void    testb()
{
    int m, n;
    int *iptr;

    n = 10;
    iptr = &n;
    n = 11;
    m = *iptr;
    
    printf("b) m = %d\n", m);
}

void    testc()
{
    int *lptr;
    int c, d;

    c = 65;
    lptr = &c;
    d = *lptr + 1;

    printf("c) d = %d\n", d);
}

void    testd()
{
    int *lptr;
    int i;

    i = 65;
    lptr = &i;

    printf("d) *lptr = %d\n", *lptr);
}

void    teste()
{
    int *lptr;
    int i, j = 4;

    lptr = &i;
    i = j;
    printf("e) *lptr = %d\n", *lptr);
}

void    testf()
{
    printf("f) garbage will be printed\n");
}


void    testg()
{
    float f = 4.0f, fred = 37.0f;

    f = fred;
    printf("g) garbage will be printed\n");
}

void    testh()
{
    int i = 9, j = 10;
    int *lptr = &i;

    *lptr = i;
    j = i;
    printf("h) *lptr = %d  i = %d  j = %d\n", *lptr, i, j);
}

void    testi()
{
    int i, j;
    int  *p1 = &i, *p2 = &j;

    *p1 = 8;
    i = 7;
    *p2 = *p1;

    printf("i) i = %d  j = %d\n", i, j);
}


void    testj()
{
    float zero = 1.0f, one;
    float *fp1 = &zero, *fp0 = &one;

    fp1 = fp0;
    *fp1 = 0.0f;
    *fp0 = 1.0f;

    printf("j) zero = %.1f one = %.1f\n", zero, one);
}


void    testk()
{
    char d, ch = 'q', grade = 'b';
    char *cp, *pp;

    cp = &grade;
    grade = 'l';
    d = *cp;
    pp = cp;
    *pp = grade; 

    printf("k) d = %c ch = %c grade = %c *cp = %c *pp = %c\n", d, ch, grade, *cp, *pp);
}        

void    testl()
{
    float f, f1 = 4.0f, f2 = 1.5f;
    float *fp1 = &f1, *fp2 = &f2;
        
    f = *fp1 ** fp2;
    
    printf("l) f = %.1f\n", f);
}   


void    testm()
{
    long lval1 = 3, lval2 = 2, *lptr;

    lptr = &lval1;
    *lptr = lval2++**lptr;

    printf("m) lval1 = %ld  lval2 = %ld\n", lval1, lval2);
}


void    testn()
{
    long lval1, lval2 = 4, *lp = &lval2, **lpp = &lp;

    lp = &lval1;
    *lp = 2;
    **lpp = 3;

    printf("n) lval1 = %ld  lval2 = %ld\n", lval1, lval2);
}


