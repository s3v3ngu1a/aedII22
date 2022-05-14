#include <stdlib.h>
#include <assert.h>
#include "pair.h"

pair_t pair_new(int x, int y) {
	pair_t p;
	p.fst = x;
	p.snd = y;
	assert((p.fst == x) && (p.snd == y));
	return p;
}

int pair_first(pair_t p) {
	int fst = p.fst;
	assert(fst == p.fst);
	return fst; 
}

int pair_second(pair_t p) {
	int snd = p.snd;
	assert(snd == p.snd);
	return snd; 
}

pair_t pair_swapped(pair_t p) {
	pair_t p_swp;
	int temp_x = p.fst;
	int temp_y = p.snd;
	p_swp.fst = temp_y;
	p_swp.snd = temp_x;
	assert((p_swp.fst == p.snd) && (p_swp.snd == p.fst));
	return p_swp;
}

pair_t pair_destroy(pair_t p) {
	return p;
}
