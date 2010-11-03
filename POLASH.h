/**
 * @file    POLASH.h
 * @author OBERLE Stephane
 */

#ifndef _POLASH_H
#define _POLASH_H

  #include "ARGV.h"
  
  int setenv (const char *name, const char *value, int overwrite);
  void clean(const char *buffer, FILE *fp);
  void help();
  void shell();

#endif