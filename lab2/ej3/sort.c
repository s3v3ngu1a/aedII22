#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"


static unsigned int partition(int a[], unsigned int izq, unsigned int der) {
    /* Needs implementation */

    /* Permutes elements of a[izq..der] and returns pivot such that:
     - izq <= pivot <= der
     - elements in a[izq,pivot) all 'go_before' (according to function goes_before) a[pivot]
     - a[pivot] 'goes_before' all the elements in a(pivot,der]
    */
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
 /* needs implementation */

	unsigned int pivot;
	if (der > izq) {
		pivot = partition(a, izq, der);
		quick_sort_rec(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
		quick_sort_rec(a, pivot + 1u, der);
	}

}

void quick_sort(int a[], unsigned int length) {
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

