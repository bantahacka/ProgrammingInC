/***************************************************************************/
/*                                                                         */
/*                      C PROGRAM EXAMPLE                                  */
/*                                                                         */
/*      FILE:        trigraph.c                                            */
/*      DESCRIPTION: Program to illustrate Trigraph sequences ??! etc      */
/*                                                                         */
/***************************************************************************/

??=include <stdio.h>                 /*  #include <stdio.h>                */
				     /*                                    */
int main(void)                       /*  int main (void)                   */
??<                                  /*  {                                 */
    printf ("Hello??/n");            /*      printf ("Hello\n");           */
    printf ("World??/n");            /*      printf ("World\n");           */
    #ifdef ERROR_DEMO                /*      #ifdef ERROR_DEMO             */
      ??=error "This is an error"    /*        #error "This is an error"   */
    #endif                           /*      #endif                        */
    return 0;                        /*      return 0;                     */
??>                                  /*  }                                 */
