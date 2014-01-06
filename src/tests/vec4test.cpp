#include "vec4.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	vec4 a, b, c;
	a = 0; b = 1; c = 1;
	if (a + b != c) return 1;
	a = vec4(0, 1, 2, 3);
	b = vec4(4, 5, 6, 7);
	c = vec4(4, 6, 8, 10);
	if (a + b != c) return 2;
	c = vec4(-4);
	if (a - b != c) return 3;
	return 0;
}
