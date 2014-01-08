#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	puts("1..3");
	vec3 a, b, c;
	a = 0; b = 1; c = 1;
	if (a + b != c) puts("not ok 1 - basic addition test failed");
	else puts("ok 1 - basic addition");
	a = vec3(0, 1, 2);
	b = vec3(4, 5, 6);
	c = vec3(4, 6, 8);
	if (a + b != c) puts("not ok 2 - addition test failed");
	else puts("ok 2 - addition");
	c = vec3(-4);
	if (a - b != c) puts("not ok 3 - subtraction test failed");
	else puts("ok 3 - subtraction");
}
