#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>


typedef int list_elem;
typedef struct _node node;
typedef node * list;
/* constructors */
list empty(void);
/* returns an empty list */

list addl(list_elem in_el, list in_ls);
/* Add an element at the begining of the list */

/* destructor */
list destroy(list in_ls);
/* free the memory used by the list */

/* operations */

bool is_empty(list in_ls);
/* returns true if in_ls is empty */

list_elem head(list in_ls);
/* PRE: not is_empty(in_ls) */
/* returns the first element of the list */

list tail(list in_ls);
/* Removes the first element of the list */
/* PRE: not is_empty(in_ls) */

list addr(list_elem in_el, list in_ls);
/* Add an element at the end of the list */

unsigned int length(list in_ls);
/* returns the amount of elements contained by in_ls */

list concat(list ls_a, list ls_b);
/* put all elements in ls_b at the end of ls_a */

list_elem index(unsigned int k, list in_ls);
/* returns the n-th element in the list being the element with index 0 the first element of the list */
/* PRE: k < length(in_ls) */

list take(unsigned int j, list in_ls);
/* leaves in in_ls only the first j elements, removing the rest */
/* PRE: j <= length(in_ls) */

list drop(unsigned int m, list in_ls);
/* removes the first n elements of in_ls */
/* PRE: j <= length(in_ls) */

list copy_list(list in_ls);
/* returns a new list containing all elements in in_ls */

#endif
