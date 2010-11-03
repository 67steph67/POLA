/**
 * @file    ARGV.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains all functions to cut words from the command line into an array.
 */

#include "ARGV.h"

/**
 * allocArgvTab
 * Function to allocate space for an array.
 *
 * @param words number of words
 * @param letters letters number per word 
 * @return an array of strings. 
 */ 
char** allocArgvTab(int words, int letters)
{
  int i;
  char **tab = (char**)malloc(words*sizeof(char*));
  for(i=0;i<words;i++)
  {
    tab[i]=(char*)malloc(letters*sizeof(char));
    memset(tab[i],'\0',letters);
  }
  return tab;
}

/**
 * freeArgvTab
 * Function to free space of an array.
 *
 * @param words number of words
 * @param arg array of strings
 * @return void 
 */ 
void freeArgvTab(int words, char** arg)
{
  int i;
  for(i=0;i<words;i++)
  {
    free(arg[i]);
  }
  free(arg);
}

/**
 * cutArgv
 * Function to cut words from the command line into an array
 *
 * @param chaine comand line
 * @param arg array of string
 * @return number of words in the array
 */ 
int cutArgv(char* chaine, char** arg)
{
  int j, l=0, k=0;
  int length = (int)strlen(chaine);
  for(j=0; j<length; j++)
  {
    if(chaine[j]==' ' && chaine[j+1]=='+' && chaine[j+2]=='\0') //If the last character is a '+' symbol.
    {								//stop
      j++;
    }
    else if(chaine[j]==' ')					//If the current character is a space
    {								//start a new word
      arg[k][l]='\0';
      k++;
      l=0;
    } 
    else if(chaine[j]=='\\' && chaine[j+1]==' ')		//If the current character is a '\' symbol with a space after
    {								//insert to the current word
      arg[k][l]=' ';						//done to allow file/dir with a space
      l++;
      j++;
    }
    else if(chaine[j]=='<' || chaine[j]=='>')			//If the current character is a '<' or '>'
    {								//nothing to do
    }
    else							//Else, we are writing a word
    {
      arg[k][l]=chaine[j];
      l++;
    }
  }
  k++;
  arg[k]=NULL;							//last word fixed as "NULL" for command execv
  return k;
}