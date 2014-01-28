#include "vec3t.h"
#include "vec2t.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "tap.h"


int main() {
	vec3 a, b, c;
	test(vec3(1) == vec3(1, 1, 1), "single component constructor");
	test(vec3f(vec3d(1)) == vec3f(1), "type conversion double -> float");
	test(vec3(vec2(1, 2)) == vec3(1, 2, 0), "conversion from vec2");
	a = 0; b = 1; c = 1;
	test(a + b == c, "basic addition");
	a = vec3(0, 1, 2);
	b = vec3(4, 5, 6);
	c = vec3(4, 6, 8);
	test(a + b == c, "addition");
	c = vec3(-4);
	test(a - b == c, "subtraction");
	test(normalize(vec3(2, 0, 0)) == vec3(1, 0, 0), "basic normalize()");
	test(normalize(vec3(1)) == vec3(1/sqrtf(3)), "normalize()");
	done();
}
