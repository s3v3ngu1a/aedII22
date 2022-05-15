/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "array_helpers.h"
#include "list.h"

/* Maximum allowed length of the array */
static const unsigned int MAX_SIZE = 100000u;

void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Compute average for the list of numbers in file.\n"
           "\n",
           program_name);
}

char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}


float average(list l) {
	float rst = 0.0;
	unsigned int len = length(l);
	list_elem el;
	list l_aux = copy_list(l);
	while(!is_empty(l_aux)) {
		el = head(l_aux);
		rst = rst + el;
		l_aux = tail(l_aux);
	}
	l_aux = destroy(l_aux);
	rst = (len > 0u) ? (rst / len): 0.0;
	return rst;
}

list array_to_list(int array[], unsigned int length) {
    /* Initialize the list */
	list out_ls = empty();
    for (unsigned int i = 0u; i < length; ++i) {
        /* Add element to the list  */
		out_ls = addr(array[i], out_ls);
    }
    /* Return list */
	return out_ls;
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    //FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);

    /* create an array of MAX_SIZE elements */
    int array[MAX_SIZE];

    /* parse the file to fill the array and obtain the actual length */
    unsigned int length = array_from_file(array, MAX_SIZE, filepath);

    /* show the array in the screen */
    array_dump(array, length);

    /* transform from array to our list type */
    list l = array_to_list(array, length);

    /* call the average function */
    printf("The average is: %.2f \n", average(l));

	l = destroy(l);

    return (EXIT_SUCCESS);
}
