#ifndef _ALPHALIB_H
#define _ALPHALIB_H

/*
 * Function: compareChars
 * Arguments: char c1, char c2
 * Return: int
 *
 * This function compares two char values according to a more sensible
 * alphabetical order. Numbers first, then capital letters, then lowercase
 * letters, and finally all other symbols.
 */
int compareChars(char c1, char c2);

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
int compareStrings(const char *str1, const char *str2);

/*
 * Function:  strSwap
 * Arguments: char *array[], unsigned int index1, unsigned int index2
 * Return: None
 *
 * Swaps the string location as indicated by index1 and index2.
 */
void strSwap(char *array[], unsigned int index1, unsigned int index2);

/*
 * Function: charSwap
 * Arguments: char *string, unsigned int index1, unsigned int index2
 * Return: None
 *
 * Swaps the position of 2 characters inside of a string.
 */
void charSwap(char *string, unsigned int index1, unsigned int index2);

#endif
