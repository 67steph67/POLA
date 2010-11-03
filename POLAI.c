/**
 * @file    POLAI.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains all functions to use pola-i
 */

#include "POLAI.h"

/**
 * defineFlags
 * Function to define the chosen authority in function of our choice
 *
 * @param c1 our choice for reading access
 * @param c2 our choice for writing access
 * @return an integer which represents the chosen authority 
 */ 
int defineFlags(char c1, char c2)
{
  int flags=-1;
  if(c1=='y' || c1=='r')
  {
    flags=0;
  }
  if(c2=='y' || c2=='r')
  {
    flags=1;
  }
  if((c1=='y' || c1=='r') && (c2=='y' || c2=='r'))
  {
    flags=2;
  }
  return flags;
}

/**
 * saveUnsave
 * Function to save the choice if needed
 *
 * @param pathname pathname of the current file/dir
 * @param c1 our choice for reading access
 * @param c2 our choice for writing access
 * @return void
 */
void saveUnsave(const char * pathname, char c1, char c2)
{
  if(c1=='r')					//If we have to save our choice for reading access
  {
    if(!isInFile(pathname, "accessR.txt"))
    {
      addFile(pathname,"accessR.txt");
    }
  }
  if(c2=='r')					//If we have to save our choice for writing access
  {
    if(!isInFile(pathname, "accessW.txt"))
    {
      addFile(pathname,"accessW.txt");
    }
  }
  
  if(c1=='n')					//If we have to unsave our choice for reading access
  {
    if(isInFile(pathname, "accessR.txt"))
    {
      suppFile(pathname,"accessR.txt");
    }
  }
  if(c2=='n')					//If we have to unsave our choice for writing access
  {
    if(isInFile(pathname, "accessW.txt"))
    {
      suppFile(pathname,"accessW.txt");
    }
  }
}

/**
 * polaI
 * main function for use pola-i
 *
 * @param pathname pathname of the current file/dir
 * @return an integer which determines the chosen authority
 */
int polaI(const char *pathname)
{
  char c1, c2;
  int flags;
  do
  {
    printf("pola request : read access to %s [n/y/r] ? ",pathname);
    scanf(" %c",&c1);
  }while(c1!='n' && c1!='y' && c1!='r');
  do
  {
    printf("pola request : write access to %s [n/y/r] ? ",pathname);
    scanf(" %c",&c2);
  }while(c2!='n' && c2!='y' && c2!='r');
  flags=defineFlags(c1,c2);	
  saveUnsave(pathname,c1, c2);
  return flags;
}