/*********************************************************************
 *                                                                   
 *  Filename:     ELEM.H
 *  Directory:    STRUCT\SOLUTION
 *
 *  Description:  This header file defines a more efficient version
 *                of a chemical element structure.
 *
 *  The following changes have been made to reduce space requirements:
 *
 *     1  Doubles replaced with floats. This is safe - none of the values
 *        in the data file are particularly accurate. The most accurate
 *        value is that for the RMM of Hydrogen. At 1.00797 it is 5
 *        decimal places (most values are 2 decimal places only).
 *        These values can easily be represented in a float.
 *
 *     2  The char  y/n  values have been scrapped. Only 1 bit containing
 *        either a 1 or 0 is required to represent the same amount of data.
 *
 *     3  The members have been rearranged so the floats fit "back to back"
 *        in successive 4 byte blocks. The "name" and the the 2-byte
 *        block of bitfields follow.
 *
 *********************************************************************/

/* Here's the new (improved) struct */

typedef struct newElementData 
{
    float      rmm;            /* The atomic weight           */
    float      mp;             /* Melting point in Kelvin     */
    float      bp;             /* Boiling point in Kelvin     */
    char       name[2];        /* The element's name          */
    unsigned   bcc     :1;     /* 1 if Block Centred Cubic    */
    unsigned   cubic   :1;     /* 1 if Cubic                  */
    unsigned   fcc     :1;     /* 1 if Face Centred Cubic     */
    unsigned   hcp     :1;     /* 1 if Hexagonal Close Packed */
    unsigned   hex     :1;     /* 1 if Hexagonal Planar       */
    unsigned   mon     :1;     /* 1 if Monoclinic             */
    unsigned   ortho   :1;     /* 1 if Orthorhombic           */
    unsigned   tetra   :1;     /* 1 if Tethrahedral           */
    unsigned   rhombic :1;     /* 1 if Rhombic                */

} NEWELEMENTDATA;


/* Here's the original (inefficient) struct */

typedef struct elementData 
{
    char    first;      /* First character of element name  */
    double  rmm;        /* Relative Molecular Mass          */
    char    second;     /* Second character of element name */
    double  mp;         /* Melting point in degrees Kelvin  */
    char    bcc;        /* 'y' if Block Centred Cubic       */
    char    cubic;      /* 'y' if Cubic                     */
    char    fcc;        /* 'y' if Face Centred Cubic        */
    double  bp;         /* Boiling point in degrees Kelvin  */
    char    hcp;        /* 'y' if Hexagonal Close Packed    */
    char    hex;        /* 'y' if Hexagonal                 */
    char    mon;        /* 'y' if Monoclinic                */
    char    ortho;      /* 'y' if Orthorhombic              */
    char    tetra;      /* 'y' if Tetrahedral               */
    char    rhombic;    /* 'y' if Rhombic                   */

} ELEMENTDATA;
