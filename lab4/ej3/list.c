#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "list.h"

struct _node {
	list_elem el;
	node *next; 
};

list empty(void) {
	/* returns an empty list */
	list out_list = NULL;

	return out_list;
}

list addl(list_elem in_el, list in_ls) {
	/* Add an element at the begining of the list */
	node *aux = NULL;
	aux = malloc(sizeof(node));
	aux->el = in_el;
	aux->next = NULL;
	if (in_ls != NULL) {
		aux->next = in_ls;
	}
	in_ls = aux;
	aux = NULL;
	return in_ls;
}

/* destructor */
list destroy(list in_ls) {
	/* free the memory used by the list */
	list follower = NULL;
	if(in_ls != NULL) {
		if (in_ls->next == NULL) {
			free(in_ls);
			in_ls = NULL;
		} else {
			follower = in_ls;
			destroy(in_ls->next);
			free(follower);
			follower = NULL;
		}
	}
	return follower;
}

/* operations */

bool is_empty(list in_ls) {
	bool res = in_ls == NULL;
	return res;
}

list_elem head(list in_ls) {
	assert(!is_empty(in_ls));
	list_elem res = in_ls->el;
	return res;
}

list tail(list in_ls) {
	assert(!is_empty(in_ls));
	node *aux = NULL;
	aux = in_ls;
	in_ls = in_ls->next;
	free(aux);
	aux = NULL;
	return in_ls;
}

list addr(list_elem in_el, list in_ls) {
	list l_aux = empty();
	node *n_aux = NULL; 
	n_aux = malloc(sizeof(node));
	n_aux->el = in_el;
	n_aux->next = NULL;
	if (in_ls == NULL) {
		in_ls = n_aux;
	} else {
		l_aux = in_ls;
		while(l_aux->next != NULL) {
			l_aux = l_aux->next;
		}
		l_aux->next = n_aux;
	}
	return in_ls;
}

unsigned int length(list in_ls) {
	unsigned int len = 0u;
	if (!is_empty(in_ls)) {
		list aux = empty();
		aux = in_ls->next;
		len = 1u + length(aux);
	}
	return len;
}

list concat(list ls_a, list ls_b) {
	list l_aux = empty();
	l_aux = ls_a;
	if(!is_empty(ls_a)) {
		while(l_aux->next != NULL) {
			l_aux = l_aux->next;
		}
		l_aux->next = ls_b;
	} else {
		l_aux = ls_b;
	}
	return ls_a;
}

list_elem index(unsigned int k, list in_ls) {
	assert(k < length(in_ls));
	list aux = empty();
	aux = in_ls;
	list_elem res = aux->el;
	unsigned int i = 0u;
	while(i < k) {
		aux = aux->next;
		res = aux->el;
		i = i + 1u;
	}
	return res;
}

list take(unsigned int j, list in_ls) {
	assert(j <= length(in_ls));
	list aux_a = in_ls;
	list aux_b = NULL;
	unsigned int i = 0u;
	while(i < j) {
		aux_b = aux_a;
		aux_a = aux_a->next;
		i = i + 1u;
	}
	aux_b->next = destroy(aux_a);
	return in_ls;
}

list drop(unsigned int m, list in_ls) {
	assert(m <= length(in_ls));
	list aux_a = in_ls;
	list aux_b = NULL;
	unsigned int i = 0u;
	while(i < m) {
		aux_b = aux_a;
		aux_a = aux_a->next;
		i = i + 1u;
	}
	aux_b->next = NULL;
	aux_b = destroy(in_ls);
	in_ls = aux_a;
	return in_ls;
}

list copy_list(list in_ls) {
	list new_list = empty();
	list aux_l = NULL;
	if (!is_empty(in_ls)) {
		list_elem aux_el= in_ls->el;
		aux_l = in_ls->next;
		new_list = addr(aux_el, new_list);
		while (aux_l != NULL) {
			aux_el = aux_l->el;
			new_list = addr(aux_el, new_list);
			aux_l = aux_l->next;
		}
	}
	return new_list;
}
