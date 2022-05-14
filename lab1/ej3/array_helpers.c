#include <stdio.h>
#include "array_helpers.h"

unsigned int array_from_file(int array[],
           unsigned int max_size,
           const char *filepath) {
	FILE *input_file;
	// input_file devuelve un FILE pointer
	input_file = fopen(filepath, "r");
	fscanf(input_file, "%u", &max_size);
	for (unsigned int index = 0u; index < max_size; ++index) {
		fscanf(input_file, "%d", &array[index]);
	}
	fclose(input_file);
	return max_size;
}

void array_dump(int a[], unsigned int length) {
	printf("[");
	for (unsigned int index = 0u; index < length; ++index) {
		if (index + 1u == length) {
			printf("%d", a[index]);
		} else {
			printf("%d, ", a[index]);
		}
	}
	printf("]\n");
}
