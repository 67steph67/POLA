/**
 * @file    POLAI.h
 * @author OBERLE Stephane
 */

#ifndef _POLAI_H
#define _POLAI_H
  
  #include "FILE.h"
  
  int polaI(const char *pathname);
  int defineFlags(char c1, char c2);
  void saveUnsave(const char * pathname, char c1, char c2);

#endif