#include "vec4.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	puts("1..4");
	vec4 a, b, c;
	a = 0; b = 1; c = 1;
	if (a + b != c) puts("not ok 1 - basic addition");
	else puts("ok 1 - basic addition");
	a = vec4(0, 1, 2, 3);
	b = vec4(4, 5, 6, 7);
	c = vec4(4, 6, 8, 10);
	if (a + b != c) puts("not ok 2 - addition");
	else puts("ok 2 - addition");
	c = vec4(-4);
	if (a - b != c) puts("not ok 3 - subtraction");
	else puts("ok 3 - subtraction");
	float s = 38;
	printf("a dot b = %f\n", dot(a, b));
	if (dot(a, b) != s) puts("not ok 4 - dot product");
	else puts("ok 4 - dot product");
	return 0;
}
