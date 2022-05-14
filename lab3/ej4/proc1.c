#include <stdlib.h>
#include <stdio.h>

void absolute(int x, int y) {
    // Completar aqui
	y = x;
	if (x < 0) {
		y = -x;
	}
}

int main(void) {
    // Completar aqui
	int a = -98;
	int res = 0;
	absolute(a, res);
	printf("The absolute value of %d is: %d\n", a, res);
    return EXIT_SUCCESS;
}

