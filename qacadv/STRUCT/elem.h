/*********************************************************************
 *                                                                   
 *  Filename:     ELEM.H
 *  Directory:    STRUCT
 *
 *  Description:  This header file contains the structure template for a
 *                chemical element in the original (wasteful) format. 
 *
 *********************************************************************/

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
