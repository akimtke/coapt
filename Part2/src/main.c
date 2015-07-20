#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "QuickSort.h"
#include "CSVReader.h"
#include "CSVWriter.h"

// Written by Aaron Kim for CoApt
// This program takes in a CSV file as an argument and sorts the file
// The way the program sorts is by first sorting from left to right and then
// down. While the program works, I am afraid there are some edge cases
// that will cause issues within the program. The program is also not as
// efficient as I would have liked it to be. Unfortunately, time was not on my
// side.

#define MAX_LINES 100
#define MAX_LENGTH 100

int main(int argc, char *argv[])
{
  if(argc < 2)
  {
    // Make sure the file was provided as an argument
    printf("Incorrect usage\n");
    printf("Usage: main filename\n");
  }
  else
  {
    char *fn = argv[1];
    char *data[MAX_LINES];
    int linesRead = readFile(fn, data, MAX_LINES, MAX_LENGTH);
    int index;
    if(linesRead > 0)
    {
      // Loops through and sorts from left to right
      for(index = 0; index < linesRead; index++)
      {
        subQSort(data[index], 0, strlen(data[index]) - 1);
      }

      // Sort from top to bottom
      QSort(data, 0, linesRead - 1);

      int result = writeCSV(fn, data, linesRead);
      if(result < 0)
      {
        printf("There was a problem writing to the file\n");
      }

      // Displays the final results
      for(index = 0; index < linesRead; index++)
      {
        printf("%s\n", data[index]);
        //free(data[index]);
      }
    }
  }
  return 0;
}
