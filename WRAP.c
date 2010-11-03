/**
 * @file    WRAP.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains all overrided functions
 */

#include "WRAP.h"

/**
 * open
 * our overrided open
 *
 * @param pathname pathname of a file
 * @param flags access modes
 * @return result from real 'open'
 */ 
int open(const char *pathname, int flags)
{
  int desc=0;
  char *msg;
  
  if(continuOpen(pathname, flags)==1)			//If we have enough permissions
  {
    if (next_open == NULL) 
    {
      next_open = dlsym(RTLD_NEXT, "open");
      if ((msg = dlerror()) != NULL) 
      {
	printf("open: dlopen failed : %s\n", msg);
	exit(1);
      } 
    }
    desc=next_open(pathname,flags);
  }
  else							//Else write in syslog
  {
    openlog("pola error",LOG_PERROR, LOG_LOCAL1); 
    syslog(LOG_SYSLOG,"access to %s is not authorized", pathname); 
    closelog(); 
  }
  return desc;
}
    
/**
 * opendir
 * our overrided opendir
 *
 * @param pathname pathname of a file
 * @return result from real 'opendir'
 */ 
int opendir(const char *pathname)
{
  int desc;
  char *msg;
  
  if(continuOpendir(pathname)==1)			//If we have enough permissions
  {
    if (next_open == NULL) 
    {
      next_opendir = dlsym(RTLD_NEXT, "opendir");
      if ((msg = dlerror()) != NULL) 
      {
	printf("opendir: dlopen failed : %s\n", msg);
	exit(1);
      } 
    }
    desc=next_opendir(pathname);
  }
  else							//Else write in syslog
  {
    openlog("pola error",LOG_PERROR, LOG_LOCAL1); 
    syslog(LOG_SYSLOG,"read access to %s is not authorized", pathname);
    closelog(); 
  }
  return desc;
}