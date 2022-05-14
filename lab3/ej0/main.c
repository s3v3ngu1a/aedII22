#include <stdlib.h>
#include <stdio.h>
#include "io_helpers.h"
#include "phrase_helpers.h"

#define MAX_SIZE 1000

void print_help(char *program_name) {
	printf ("Usage: %s <input file path>\n\n"
			"Resemble a text given an index and a character in a file in disk\n"
			"The input file must contain in each line the following format:\n"
			"<int> '<char>'\n\n", program_name);
}

char *parse_filepath(int argc, char *argv[]) {
	char *result = NULL;
	if (argc < 2) {
		print_help(argv[0]);
		exit(EXIT_FAILURE);
	}

	result = argv[1];
	return result;
}

static void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
	filepath = parse_filepath(argc, argv);

    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length=0; 
    //  .----------^
    //  :
    // Debe guardarse aqui la cantidad de elementos leidos del archivo
    
    /* -- completar -- */
	length = data_from_file(filepath, indexes, letters, MAX_SIZE);

	phrase_rebuild(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

