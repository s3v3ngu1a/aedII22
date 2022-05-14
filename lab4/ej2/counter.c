#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>

#include "counter.h"

struct _counter {
    unsigned int count;
};

counter counter_init(void) {
	counter init_count = NULL;
	init_count = malloc(sizeof(unsigned int));
	init_count->count = 0u;
	return init_count;
}

void counter_inc(counter c) {
	c->count = (c->count) + 1u;
}

bool counter_is_init(counter c) {
	bool res = (c->count) == 0u;
	return res;
}

void counter_dec(counter c) {
	assert(!counter_is_init(c));
	c->count = (c->count) - 1u;
}

counter counter_copy(counter c) {
	counter new_counter = counter_init();
	new_counter->count = c->count;
	return new_counter;
}

void counter_destroy(counter c) {
	free(c);
	c = NULL;
}
