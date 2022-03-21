/*********************************************************************
 *                                                                   
 *  Filename:     ELEM.H
 *  Directory:    SORTSRCH
 *
 *  Description:  This header file defines an efficient version
 *                of a chemical element structure (same as solution
 *                to Structures question 1)
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

