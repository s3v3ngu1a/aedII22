#ifndef ARRAY_HELPERS_H
#define ARRAY_HELPERS_H
/* was replaced by the local implementation  <stdbool.h> */
#include "mybool.h"

/* read an array size from file and the elements of each position */
unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath);

/* prints to stdout the content of the array */
void array_dump(int a[], unsigned int length);

/* define if the given array is sorted in ascendent order */
mybool array_is_sorted(int a[], unsigned int length);
#endif
