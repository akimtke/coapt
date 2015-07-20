#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSVReader.h"

/*
 * Function: readFile
 * Arguments: const char *filename, char *dest[], int numLines, int numChars
 * Return: Number of lines read or a -1 if there was an Error
 *
 * Reads the file and parses it dumping the contents into the array provided.
 * Yes, this could be better. Perhaps using a library but I wanted to try this
 * for myself. The downside to this is it is not flexible enough and does not
 * consider commas as tokens. This function also assumes there is one characters
 * and I think it should accomodate for the possibility of having a string
 * instead. Unfortunately, the way I implemented this program meant that it has
 * to be a single character.
 */
int readFile(const char *filename, char *dest[], int numLines, int numChars)
{
  FILE *file_handle;
  file_handle = fopen(filename, "r");
  if(file_handle == NULL)
  {
    fprintf(stderr, "Error: Unable to open csv file for reading\n");
    return -1;
  }

  int index = 0;
  int cIndex = 0;
  char buffer[numChars];
  char *token;

  // Allocate space in the array
  dest[index] = malloc(numChars * sizeof(char));
  while(fgets(buffer, numChars, file_handle) != NULL && index < numLines)
  {
    // Gets the tokens one at a time and places them into the array
    token = strtok(buffer, ",");
    while(token != NULL && cIndex < numChars)
    {
      // In case there is whitespace, remove it
      while(*token == ' ')
      {
        token++;
      }
      dest[index][cIndex] = *token;
      token = strtok(NULL, ",");
      cIndex++;
    }
    cIndex = 0;
    index++;
    // Allocate space in the next spot
    dest[index] = malloc(numChars * sizeof(char));
  }

  fclose(file_handle);
  return index;
}
