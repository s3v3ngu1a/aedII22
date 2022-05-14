#include <stdlib.h>
#include <stdio.h>

unsigned int data_from_file(const char *path,
							unsigned int indexes[],
							char letters[],
							unsigned int max_size) {
	FILE *file = NULL;
	file = fopen(path, "r");
	if (file == NULL) {
		fprintf(stderr, "File does not exist.\n");
		exit(EXIT_FAILURE);
	}
	unsigned int i = 0u;
	while (!feof(file) && i < max_size) {
		fscanf(file, "%u \'%c\'\n", &indexes[i], &letters[i]);
		i = i + 1u;
	}
	fclose(file);
	return i;
}
