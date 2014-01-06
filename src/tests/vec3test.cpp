#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	vec3 a, b, c;
	a = 0; b = 1; c = 1;
	if (a + b != c) return 1;
	a = vec3(0, 1, 2);
	b = vec3(4, 5, 6);
	c = vec3(4, 6, 8);
	if (a + b != c) return 2;
	c = vec3(-4);
	if (a - b != c) return 3;
	return 0;
}
