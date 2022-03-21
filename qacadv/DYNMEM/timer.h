/*********************************************************************
 *                                                                   
 *  Filename:     TIMER.H
 *  Directory:    DYNMEM
 *
 *  Description:  This file defines a useful timer function and
 *                a related enum.
 *
 *********************************************************************/

enum timerOptions { Undefined, Start, Stop, Show };

void timer(enum timerOptions);
