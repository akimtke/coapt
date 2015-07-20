#ifndef _CSVREADER_H
#define _CSVREADER_H

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
int readFile(const char *filename, char *dest[], int numLines, int numChars);

#endif
