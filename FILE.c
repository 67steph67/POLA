/**
 * @file    FILE.c
 * @author OBERLE Stephane
 *
 * @section DESCRIPTION
 *
 * This file contains all functions to read/write in text files.
 */

#include "FILE.h"

/**
 * addFile
 * Function to add a pathname in the file
 *
 * @param pathname pathname of the file/dir
 * @param file text file
 * @return void 
 */ 
void addFile(const char *pathname, char* file)
{
  FILE* fichier = NULL;
  fichier = fopen(file, "a");
  fprintf(fichier, "%s:", pathname);
  fclose(fichier);
}

/**
 * isInFile
 * Function to test if a pathname is in the file
 *
 * @param pathname pathname of the file/dir
 * @param file text file
 * @return boolean
 */ 
int isInFile(const char *pathname, char* file)
{
  FILE* fichier = NULL;
  char chaine[1024] = "";
  char str[100]; 
  memset(str,'\0',80);				//str = "pathname:"
  strcat(str,pathname);
  strcat(str,":");
  fichier = fopen(file, "r");
  if (fichier != NULL)
  {
    fgets(chaine, 5000, fichier);		//Read string from the text file
    fclose(fichier);
  }
  if(strstr(chaine,str)==NULL)			//Test if str is in the string
  {
    return 0;
  }
  else return 1;
}

/**
 * suppFile
 * Function to delete a pathname from the file
 *
 * @param pathname pathname of the file/dir
 * @param file text file
 * @return void
 */ 
void suppFile(const char *pathname, char* file)
{
  FILE* fichier = NULL;
  char chaine[1024] = "";
  char tmp[150]="";
  int i=0,j=0;
  int size, stop=0, cut;
  fichier = fopen(file, "r");
  fgets(chaine, 1024, fichier);			//Read string from the file
  fclose(fichier);
  size = (int)strlen(chaine);
  while(i<size && stop==0)			//Find where is the pathname in the string
  {
    if(chaine[i]==':')
    {
      if(strcmp(tmp,pathname)==0)
      {
	cut=i-(int)strlen(tmp);
	stop=1;
      }
      else
      {
	memset(tmp,'\0',150);
	j=0;
      }
      i++;
    }
    else
    {
      tmp[j]=chaine[i];
      i++;
      j++;
    }
  }
  for(i=cut;i<size;i++)				//Delete the pathname from the string
  {
    chaine[i]=chaine[i+(int)strlen(tmp)+1];
  }
  fichier = fopen(file, "w");
  fprintf(fichier, "%s", chaine);		//Write the new string in the file
  fclose(fichier);
}
