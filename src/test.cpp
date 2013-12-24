#include "vec4.h"
#include "vec3.h"
#include "vec2.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
	vec4 a4 = vec4(1, 2, 3, 4);
	a4 *= 2;
	if (a4 != vec4(2, 4, 6, 8)) {
		puts("vec4 equality test failed on test 1.");
		exit(-1);
	}
	if (vec3(1) != vec3(1)) {
		puts("vec3 equality test failed on test 2.");
		exit(-1);
	}
	if (vec2(1) != vec2(1)) {
		puts("vec2 equality test failed on test 3.");
		exit(-1);
	}
	puts("All tests succeded.");
}
