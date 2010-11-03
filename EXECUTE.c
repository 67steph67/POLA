/**
 * @file    EXECUTE.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains the function 'execute'
 */

#include "EXECUTE.h"

/**
 * execute
 * Function to execute the command line
 *
 * @param argv array of words from the command line
 * @return void 
 */ 
void execute(char** argv)
{
  int pid,status;
  pid=fork();
  if (pid < 0) 
  {
    fprintf(stderr,"Erreur Fork()\n");
  } 
  if (pid==0) 
  {
    if((execvp(argv[0], argv))==-1)
    {
      printf("No command '%s' found\n",argv[0]);
    }
  }	
  else if(pid>0)
  {
    waitpid(pid,&status,0);
  } 
}