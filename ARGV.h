/**
 * @file    MOD.h
 * @author OBERLE Stephane
 */

#ifndef _MOD_H
#define _MOD_H

  #include "EXECUTE.h"

  char** allocArgvTab(int words, int letters);
  void freeArgvTab(int words, char** arg);
  int cutArgv(char* chaine, char** arg);


#endif