#include <stdio.h>
#include <stdbool.h>
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


bool array_is_sorted(int a[], unsigned int length) {
	bool res = true;
	unsigned int index = 0u;
	while (index + 1u < length && res) {
		if (a[index] > a[index + 1u]) {
			res = false;
		}
		index = index + 1u;
	}
	return res;
}
