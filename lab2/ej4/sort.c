#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; ++j) {
        if (!goes_before(a[min_pos],a[j])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0u; i < length; ++i) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


static void insert(int a[], unsigned int i) {
    /* copiá acá la implementación que hiciste en el ejercicio 1 */
	unsigned int j = i;
	while (j > 0u && goes_before(a[j], a[j - 1u])) {
		swap(a, j, j-1u);
		j--;
	}
}

void insertion_sort(int a[], unsigned int length) {
    for (unsigned int i = 1u; i < length; ++i) {
        insert(a, i);
    }
}


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 3 */
	unsigned int pivot = izq;
	unsigned int aux_i = izq + 1u;
	unsigned int aux_d = der;
	while (aux_i <= aux_d) {
		if (goes_before(a[aux_i], a[pivot])) {
				aux_i++;
		} else if (goes_before(a[pivot], a[aux_d])) {
			aux_d--;
		}
		else {
			swap(a, aux_i, aux_d);
		}
	}
	swap(a, aux_d, pivot);
	pivot = aux_d;
	return pivot;
}

static void quick_sort_rec(int a[], unsigned int izq, unsigned int der) {
    /* copiá acá la implementación que hiciste en el ejercicio 2 */
	unsigned int pivot;
	if (der > izq) {
		pivot = partition(a, izq, der);
		quick_sort_rec(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
		quick_sort_rec(a, pivot + 1u, der);
	}
}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}
