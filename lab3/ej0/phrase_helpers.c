#include <stdlib.h>


void phrase_rebuild(unsigned int indexes[], char letters[],
					char sorted[], unsigned int length) {
	unsigned int i = 0u;
	while(i < length) {
		sorted[indexes[i]] = letters[i];
		i = i + 1u;
	}
}
