/*********************************************************************
 *                                                                   
 *  Filename:     PARENT.C
 *  Directory:    PROCESS
 *
 *  Description:  This program invokes the child process CHILD.EXE
 *                with several command-line arguments.
 *
 *                The spawnl() function is used to run the child process.
 *
 *********************************************************************/

#include <stdio.h>
#include <process.h>

int main(void)
{
    /* Add code to display a starting message    */


    /* Add code to spawn the child process       */


    /* Add code to display an ending message,    */
    /* along with the value returned by _spawnl() */

    
    /* Pause for a key before terminating */
    printf("Press any key to exit the parent\n");
    getchar();

    return 0;
}
