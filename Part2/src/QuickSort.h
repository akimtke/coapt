#ifndef _QUICKSORT_H
#define _QUICKSORT_H

/*
 * Function: subQSort
 * Arguments: char *array, int first, int last
 * Return: None
 *
 * Sorts a string using the quicksort algorithm.
 */
void subQSort(char *array, int first, int last);

/*
 * Function: QSort
 * Arguments: char *array[], int first, int last
 * Returns: None
 *
 * Sorts an array of strings using the quicksort algorithm
 */
void QSort(char *array[], int first, int last);

#endif
