#include <stdio.h>
#include "QuickSort.h"
#include "AlphaLib.h"

/*
 * Function: subQSort
 * Arguments: char *array, int first, int last
 * Return: None
 *
 * Sorts a string using the quicksort algorithm.
 */
void subQSort(char array[], int first, int last)
{
  int pivot;
  int index;
  int divider;

  // Check for base case
  if(first < last)
  {
    pivot = last;
    index = first;
    divider = first;
    while(index < pivot)
    {
      // Compare characters and if needed, swap them
      if(compareChars(array[index], array[pivot]) <= 0)
      {
        // The character comes before the pivot alphabetically so swap
        charSwap(array, divider, index);
        divider++;
      }
      index++;
    }
    // Put the pivot value in the middle of the array
    charSwap(array, divider, pivot);
    // Recurse!
    subQSort(array, first, divider - 1);
    subQSort(array, divider + 1, last);
  }
}

/*
 * Function: QSort
 * Arguments: char *array[], int first, int last
 * Returns: None
 *
 * Sorts an array of strings using the quicksort algorithm. I would have liked
 * a single quicksort function but my implementation approach dicated a need
 * for a separate function.
 */
void QSort(char *array[], int first, int last)
{
  int pivot;
  int index;
  int divider;
  // Check for base case
  if(first < last)
  {
    pivot = last;
    index = first;
    divider = first;
    while(index < pivot)
    {
      // If the string comes before alphabetically, then swap
      if(compareStrings(array[index], array[pivot]) < 0)
      {
        strSwap(array, divider, index);
        divider++;
      }
      index++;
    }
    // Put the pivot where it belongs
    strSwap(array, divider, pivot);

    // Recurse!
    QSort(array, first, divider - 1);
    QSort(array, divider + 1, last);
  }
}
