#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "QuickSort.h"

/*
 * Function: compareChars
 * Arguments: char c1, char c2
 * Return: int
 *
 * This function compares two char values according to a more sensible
 * alphabetical order. Numbers first, then capital letters, then lowercase
 * letters, and finally all other symbols.
 */
int compareChars(char c1, char c2)
{
  int result = 0;

  if(isdigit(c1) || isalpha(c1))
  {
    if(isdigit(c2) || isalpha(c2))
    {
      // They are both alphanumeric or an alpha character so just return the
      // difference
      result = c1 - c2;
    }
    else
    {
      // The second character is some kind of symbol so put it in the back
      result = -1;
    }
  }
  else if(isdigit(c2) || isalpha(c2))
  {
    // The first character is some kind of symbol
    result = 1;
  }

  return result;
}

/*
 * Function: compareStrings
 * Arguments: const char *str1, const char *str2
 * Return: int
 *
 * Compares two strings but not like the strcmp function in string.h. This
 * function uses the compareChars function as defined above to determine the
 * order of the strings. This will be instrumental in the qsort algorithm. The
 * return value is > 0 if str1 > str2 (str1 is alphabetically after str2), == 0
 * if they are the same, and < 0 if str1 < str2 (str1 is alphabetically before
 * str2).
 */
int compareStrings(const char *str1, const char *str2)
{
  int result;

  if(*str1 == '\0' || *str2 == '\0')
  {
    // This is the base case which means either string is at the end. If that is
    // the case, figure out if which one and put the shorter string in front of
    // the longer one.
    if(str1 != '\0')
    {
      // str2 is shorter
      result = 1;
    }
    else if(str2 != '\0')
    {
      // str1 is shorter
      result = -1;
    }
    else
    {
      // This means that both strings are the same length and equal
      result = 0;
    }
  }
  else if(*str1 != *str2)
  {
    // If the character is not the same, then return the result of comparing them
    result = compareChars(*str1, *str2);
  }
  else
  {
    // If the characters are equal, then recurse
    result = strcmp(++str1, ++str2);
  }

  return result;
}

/*
 * Function:  strSwap
 * Arguments: char *array[], unsigned int index1, unsigned int index2
 * Return: None
 *
 * Swaps the string location as indicated by index1 and index2.
 */
void strSwap(char *array[], unsigned int index1, unsigned int index2)
{
  char *temp;
  temp = array[index1];
  array[index1] = array[index2];
  array[index2] = temp;
}

/*
 * Function: charSwap
 * Arguments: char *string, unsigned int index1, unsigned int index2
 * Return: None
 *
 * Swaps the position of 2 characters inside of a string.
 */
void charSwap(char *string, unsigned int index1, unsigned int index2)
{
  char temp;
  temp = string[index1];
  string[index1] = string[index2];
  string[index2] = temp;
}
