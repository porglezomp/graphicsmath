#include "vec4.h"
#include "vec3.h"
#include "vec2.h"
#include <stdio.h>
#include <cassert>

int main() {
	vec4 a4 = vec4(1, 2, 3, 4);
	a4 *= 2;
	assert(a4 == vec4(2, 4, 6, 8));
	assert(vec3(1) == vec3(1));
	assert(vec2(1) == vec2(1));
	puts("All tests succeded.");
}
