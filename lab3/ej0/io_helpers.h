#ifndef _IO_HELPERS_H
#define _IO_HELPERS_H

unsigned int data_from_file(const char *path,
							unsigned int indexes[],
							char letters[],
							unsigned int max_size);
	// Given a file with the following format: <int> <char>
	// maps it's content to indexes and letters
#endif
