/**
 * @file    ACCESS.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains functions which test the presence of the file/dir name, '<...>' or '+' on the command line.
 */

#include "ACCESS.h"
  
/**
 * Raccess
 * Function which test if the file/dir name is on the command line
 *
 * @param pathname name of the file/dir
 * @return boolean
 */ 
int Raccess(const char *pathname)
{
  int res = 0;
  char* chaine = getenv("VAR");
  if(strstr(chaine,pathname)!=NULL)
  {
    res = 1;
  }
  return res;
}

/**
 * Caccess
 * Function which test if there is the file is surrounded with "<...>" on the command line.
 *
 * @param pathname name of the file/dir
 * @return boolean
 */ 
int Caccess(const char* pathname)
{  
  int res=0;
  char* chaine = getenv("VAR");
  char str[80]; 
  memset(str,'\0',80);
  strcat(str,"<");
  strcat(str,pathname);
  strcat(str,">");
  if(strstr(chaine,str)!=NULL)
  {
    res=1;
  }
  return res;
}
  
/**
 * Paccess
 * Function which test if there is a '+' symbol at the end of the command line.
 *
 * @param /
 * @return boolean
 */ 
int Paccess()
{
  int res=0;
  char* chaine = getenv("VAR");
  int length = (int)strlen(chaine);
  if(chaine[length-1]=='+')
  {
    res=1;
  }
  return res;
}