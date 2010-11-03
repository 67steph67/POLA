/**
 * @file    CONTINU.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains functions which test needed conditions to execute 'open/opendir'
 */

#include "CONTINU.h"

/**
 * continuOpen
 * Function to test if we can execute 'open'
 *
 * @param pathname pathname of a file
 * @param flags access modes
 * @return boolean
 */ 
int continuOpen(const char *pathname, int flags)
{
  int res=0;
  int monflags=-1;
  if(strcmp(getenv("POLAI"),"yes")==0)
  {
    monflags=polaI(pathname);
    if(flags==0 && (monflags==0|| monflags==2))
    {
      res=1;
    }
    if((flags&1==1) && (monflags==1 || monflags==2))
    {
      res=1;
    }
    if((flags&2==1) && monflags==2)
    {
      res=1;
    }
  }
  else
  {
    if(flags==0 && isInFile(pathname, "accessR.txt"))
    {
      res=1;
    }
    if((flags&1==1) && isInFile(pathname, "accessW.txt"))
    {
      res=1;
    }
    if((flags&2==1) && (isInFile(pathname, "accessR.txt") && isInFile(pathname, "accessW.txt")))
    {
      res=1;
    }
    else
    {
      if(flags==0 && Raccess(pathname)==1)
      {
	  res=1;
      }
      if(flags&1==1 && (Paccess()==1 || Caccess(pathname)==1))
      {
	  res=1;
      }
      if(flags&2==1 && ((Caccess(pathname)==1 || Paccess()==1) &&  Raccess(pathname)==1))
      {
	  res=1;
      }
    }
  }
  return res;
}

/**
 * continuOpendir
 * Function to test if we can execute 'opendir'
 *
 * @param pathname pathname of a file
 * @return boolean
 */ 
int continuOpendir(const char *pathname)
{
  int res=0;
  int flags=-1;
  if(strcmp(getenv("POLAI"),"yes")==0)
  {
    flags=polaI(pathname);
    if(flags==0 || flags==2)
    {
      res=1;
    }
  }
  else if(isInFile(pathname, "accessR.txt"))
  {
    res=1;
  }
  else if(Raccess(pathname)==1)
  {
    res=1;
  }
  return res;
}