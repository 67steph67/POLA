/**
 * @file    FILE.h
 * @author OBERLE Stephane
 */

#ifndef _FILE_H
#define _FILE_H

  #define _GNU_SOURCE
  #include <stdlib.h>
  #include <stdio.h>
  #include <dlfcn.h>
  #include <string.h>
  #include <sys/stat.h>
  
  void addFile(const char *pathname, char* file);
  int isInFile(const char *pathname, char* file);
  void suppFile(const char *pathname, char* file);
  
#endif