/* Link2.c */

/* 
   1.  Read a file into a linked list 
   2.  Retrieve items from it
*/

/* Local definitions */
#define MAX_LINE_LEN 80      /* Maximum line length of input file */

/* Library header files */
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

/* Local header files */
#include "Link2.h"

/* Local prototypes */
static int iPopulate (FILE *pFile);
static void HandleError (const char *szMessage);
static void AddItem (const char *pszName, const char *pszNumber);
static Node * GetNode (char *pszName);
static void PrintNode (Node *pNode);
static void PrintList (void);

/* Globals */
Node *g_pAnchor = NULL;

/* ----------------------------------------------------------------------------------- */

int main (int argc, char *argv[])
{
   FILE *pFile;
   const char *pszFileName;
   int iRetn;

   if (argc < 2)
      pszFileName = "phone.txt";
   else
      pszFileName = argv[1];

   pFile = fopen (pszFileName, "r");

   if (!pFile)
      HandleError (pszFileName);

   iRetn = iPopulate (pFile);

   fclose (pFile);

   while (1)
   {
      char szName[MAX_LINE_LEN];

      printf("\nEnter a name to retrieve ('q' to quit): ");
      fflush(stdin);
      
      /* Don't use scanf because it breaks on whitespace */
      fgets (szName, MAX_LINE_LEN, stdin);
      /* Remove '\n' */
      szName[strlen(szName)-1]='\0';

      if (!strcmp(szName, "q"))
          break;
        
      PrintNode (GetNode(szName));
           
      printf("\nThe list is now:\n");
      PrintList();
   }

   return 0;

}  /* main */

/* ----------------------------------------------------------------------------------- */

static int iPopulate (FILE *pFile)
{
   char szBuffer [MAX_LINE_LEN+1] = {0};

   while (fgets (szBuffer, MAX_LINE_LEN, pFile))
   {
      char *pNumber = strchr(szBuffer, ',');
      unsigned int iPos;

      if (pNumber)
      {
         *pNumber = '\0';
         pNumber++;
      }

      /* chomp new-line from end of record */
      iPos = strlen(pNumber) - 1;

      if (pNumber[iPos] == '\n')
         pNumber[iPos] = '\0';


      AddItem (szBuffer, pNumber);
      
   }

   return errno;

}  /* iPopulate */

/* ----------------------------------------------------------------------------------- */

static void AddItem (const char *pszName, const char *pszNumber)
{
   int iLen;

   /* Create the new node */
   Node *pNew = calloc (1, sizeof(Node));     

   if (!pNew)
      HandleError ("malloc Node in AddItem");

   /* Dynamically allocate memory for the name */
   pNew->pszName = malloc (strlen(pszName)+1);

   if (!pNew->pszName)
   {
      char szMsg[80];
      sprintf (szMsg, "malloc %d bytes in AddItem", strlen(pszName)+1);
      HandleError (szMsg);
   }
  
   strcpy (pNew->pszName, pszName);

   /* Phone number has a maximum length, check that it is not exceded */
   iLen = strlen(pszNumber);

   if (iLen > MAX_PHONE)
      iLen = MAX_PHONE;

   strncpy (pNew->szPhone, pszNumber, iLen);

   /* Update the 'next' pointer */
   pNew->pNext = g_pAnchor;
   
   /* Now push it onto the linked list */
   g_pAnchor = pNew;

}  /* AddItem */

/* ----------------------------------------------------------------------------------- */

static Node * GetNode (char *pszName)
{
   /* 
      TODO 
      
      Part 1
         Search the list for the specified name
         Return a pointer to the node, or NULL if not found

      Part 2
         Move the retrieved item to the head (g_pAnchor) of the list

   */


  

}   /*  GetNode */

/* ----------------------------------------------------------------------------------- */

static void PrintNode (Node *pNode)
{

   if (pNode )
      printf ("%-40s\t%-s\n", pNode->pszName, pNode->szPhone); 
   else
      printf ("*** No such entry\n"); 


}  /* PrintNode */

/* ----------------------------------------------------------------------------------- */

static void PrintList (void)
{
   Node *pNode;

   for (pNode = g_pAnchor; pNode; pNode = pNode->pNext)
      PrintNode (pNode);   

}  /* PrintList */

/* ----------------------------------------------------------------------------------- */

static void HandleError (const char *szMessage)
{
   perror (szMessage);
   
   exit (errno);

}  /* HandleError */

/* ----------------------------------------------------------------------------------- */
