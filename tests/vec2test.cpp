#include "vec2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	vec2 a, b, c;
	a = 0; b = 1; c = 1;
	if (a + b != c) return 1;
	a = vec2(0, 1);
	b = vec2(4, 5);
	c = vec2(4, 6);
	if (a + b != c) return 2;
	c = vec2(-4);
	if (a - b != c) return 3;
	return 0;
}
