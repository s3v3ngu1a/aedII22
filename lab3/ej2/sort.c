/*
  @file sort.c
  @brief sort functions implementation
*/

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "helpers.h"
#include "sort.h"
#include "player.h"

bool goes_before(player_t x, player_t y){
	bool res = true;
    // completar aquí
	if (x.rank > y.rank) {
		res = false;
	}
    return res;
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1u;
    while (i < length && goes_before(atp[i - 1u], atp[i])) {
        i++;
    }
    return (i == length);
}
void swap(player_t a[], unsigned int i, unsigned int j){
	if ( i != j) {
		player_t aux_pl_i = a[i];
		player_t aux_pl_j = a[j];
		a[j] = aux_pl_i;
		a[i] = aux_pl_j;
	}
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
	unsigned int pivot = izq;
	unsigned int aux_i = izq + 1u;
	unsigned int aux_d = der;
	while (aux_i <= aux_d) {
		if (goes_before(a[aux_i], a[pivot])) {
			aux_i++;
		} else if (goes_before(a[pivot], a[aux_d])) {
			aux_d--;
		} else {
			swap(a, aux_i, aux_d);
		}
	}
	swap(a, aux_d, pivot);
	pivot = aux_d;
	return pivot;
}
static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
	unsigned int pivot;
	if (der > izq) {
		pivot = partition(a, izq, der);
		quick_sort_rec(a, izq, (pivot == 0u) ? 0u : pivot - 1u);
		quick_sort_rec(a, pivot + 1u, der);
	}
}
void sort(player_t a[], unsigned int length) {
    // completar aquí
	quick_sort_rec(a, 0u, (length == 0u) ? 0u : length - 1u);
}

