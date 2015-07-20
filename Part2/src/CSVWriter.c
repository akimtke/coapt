#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CSVWriter.h"

/*
 * Function: writeCSV
 * Arguments: char *filename, char *array[], int numLines
 * Return: 1 if successful, -1 if not
 *
 * Writes an array of strings to a CSV file. Again, I wish I could implement
 * this better had I more time. Unfortumately, I am afraid there is some edge
 * case that will cause an error or funky behavior.
 */
int writeCSV(char *filename, char *array[], int numLines)
{
  FILE *file_handle;
  file_handle = fopen(filename, "w");
  if(file_handle == NULL)
  {
    // Error! Print a meaningful message
    fprintf(stderr, "Error: Unable to open csv file for writing\n");
    printf("Can't open file for writing\n");
    return -1;
  }

  int outer;
  int inner;

  for(outer = 0; outer < numLines; outer++)
  {
    inner = 0;
    while(array[outer][inner] != '\0')
    {
      fprintf(file_handle, "%c", array[outer][inner]);
      // Write out the commas but don't add a comma if the element is the last
      // to be written
      if(array[outer][inner + 1] != '\0')
      {
        fprintf(file_handle, ",");
      }
      inner++;
    }
    fprintf(file_handle, "\n");
  }

  fclose(file_handle);
  return 0;
}
