#include <stdio.h>

#include "test.h"

#include "vec2.h"
#include "vec3.h"
#include "quat.h"

void print_quat(const quat &q) {
	printf("# %f %f %f %f\n", q.x, q.y, q.z, q.w);
}

void print_vec(const vec3 &v) {
	printf("# %.10f %.10f %.10f\n", v.x, v.y, v.z);
}

// Better check: v == v if (v cross v) == 0
// Can survive small floating point error
bool vec_equal(const vec3 &a, const vec3 &b) {
	return length(cross(a, b)) == 0;
}

bool vec_equal(const vec2 &a, const vec2 &b) {
	return vec_equal(vec3(a), vec3(b));
}

int main() {
	quat q;
	q = angleAxis(90, vec3(0, 0, 1));
	print_quat(q);
	test(quat() == quat(0, 0, 0, 1), "identity");
	test(quat() == quat(), "identity equals identity");
	test(quat(1, 2, 3, 4) == quat(1, 2, 3, 4), "equality");
	vec3 v3 = q.rotate(vec3(0, 1, 0));
	test(vec_equal(v3, vec3(-1, 0, 0)), "rotation");
	vec2 v2 = q.rotate(vec2(0, 1));
	test(vec_equal(v2, vec2(-1, 0)), "rotation 2d");
	test(quat() * quat() == quat(), "multiplication - identity");
	test(quat() * quat(1, 2, 3, 4) == quat(1, 2, 3, 4), "multiplication by identity");
	done();
	return 0;
}