/**
 * @file    EXECUTE.h
 * @author OBERLE Stephane
 */

#ifndef _EXECUTE_H
#define _EXECUTE_H

  #include <stdlib.h>
  #include <stdio.h>
  #include <unistd.h>
  #include <string.h>
  #include <sys/wait.h> 
  #include <sys/types.h> 
  #include <dirent.h>
  #include <sys/stat.h>

  void execute(char** argv);

#endif