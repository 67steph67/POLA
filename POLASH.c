/**
 * @file    POLASH.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains all functions needed for our basic shell.
 */

#include "POLASH.h"

/**
 * clean
 * Function to clean buffer
 *
 * @param buffer our buffer
 * @param fp 'stdin'
 * @return void
 */ 
void clean(const char *buffer, FILE *fp)
{
  char *p = strchr(buffer,'\n');
  if (p != NULL)
  {
      *p = 0;
  }
  else
  {
    int c;
    while ((c = fgetc(fp)) != '\n' && c != EOF);
  }
}

/**
 * help
 * Function to view help
 *
 * @return void
 */ 
void help()
{
  printf("--------------------------------------------------------------------------------------------------\n");
  printf(" POLA HELP :\n");
  printf("  The principle of least authority (POLA) is the practice of limiting access\n");
  printf("  to the minimal level that will allow normal functioning.\n");
  printf("\n   POLASH :\n");
  printf("   # Reading access :\n");
  printf("\t- The file/dir must be present on the command line.\n");
  printf("\t  Example : 'ls .'\n");
  printf("   # Writing access :\n");
  printf("\t- The file must be surrounded with '<...>' on the commad line.\n");
  printf("\t  Example : touch <file>\n");
  printf("\t- A + symbol is present at the end od the command line\n");
  printf("\t  Example : touch file +\n");
  printf("\n   POLA-I :\n");
  printf("\t- Command : 'pola-i'\n");
  printf("\t  Example : 'pola-i ls .'\n");
  printf("\t  Choice : [n/y/r]\n");
  printf("\t   n : 'no', does not allow the requested access.\n");
  printf("\t   y : 'yes', allow the requested access.\n");
  printf("\t   r : 'remember yes', allow the requested access and save your choice.\n");
  printf("\t       You can unsave this choice by choosing 'n' for the requested access the next time.\n");
  printf("--------------------------------------------------------------------------------------------------\n");
}

/**
 * shell
 * Main function to use our basic shell
 *
 * @return void
 */ 
void shell()
{
  int i;
  int quit=0;
  int argc;
  char * chaine = (char*)malloc(100*sizeof(char));
  char ** argv; 
  char LDPRELOAD[200]="";
  strcat(LDPRELOAD,getenv("PWD"));			//set the pathname of our dynamic lib
  strcat(LDPRELOAD,"/POLALIB.so");
 
  while(quit==0)					//infinite loop
  {
    printf("POLA > ");					
    
    setenv("LD_PRELOAD",LDPRELOAD,1);			//load our dynamic lib
    setenv("POLAI","no",1);				//Set the environment variable 'POLAI'
    
    fgets(chaine, 100, stdin);				//Reading on stdin
    clean(chaine, stdin);    
    setenv("VAR",chaine,1);				//Set the environment variable 'VAR' to access it in our lib
    
    argv = allocArgvTab(10,30);				//Allocate space for our array
    argc=cutArgv(chaine, argv);				//Cut the command line into the array
    
    if(strcmp(argv[0],"exit")==0)			//if the requested command is 'exit'
    {
      remove("accessR.txt");
      remove("accessW.txt");
      quit=1;
    }
    else if(strcmp(argv[0],"pola-i")==0)		//if the requested command is 'exit'
    {
      setenv("POLAI","yes",1);				//Set the environment variable 'POLAI' 
      for(i=0;i<argc;i++)				//Cut 'pola-i' and execute the command line
      {
	argv[i]=argv[i+1];
      }
      execute(argv);
    }
    else if(strcmp(argv[0],"help")==0)			//if the requested command is 'help'
    {
      help();
    }
    else
    {
      execute(argv);
    }
    freeArgvTab(10, argv);				
  }
  free(chaine);
}



