#include "vec3.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	puts("1..5");
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
	if (normalize(vec3(2, 0, 0)) != vec3(1, 0, 0)) puts("not ok 4 - basic normalize() failed");
	else puts("ok 4 - basic normalize()");
	if (normalize(vec3(1)) != vec3(1/sqrtf(3))) puts("not ok 5 - normalize() failed");
	else puts("ok 5 - basic normalize()");
}
