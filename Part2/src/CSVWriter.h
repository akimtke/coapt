#ifndef _CSVWRITER_H
#define _CSVWRITER_H

/*
 * Function: writeCSV
 * Arguments: char *filename, char *array[], int numLines
 * Return: 1 if successful, -1 if not
 *
 * Writes an array of strings to a CSV file. Again, I wish I could implement
 * this better had I more time. Unfortumately, I am afraid there is some edge
 * case that will cause an error or funky behavior.
 */
int writeCSV(char *filename, char *array[], int numLines);

#endif
