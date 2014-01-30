#include "vec2.h"
#include "mat2.h"
#include "test.h"

void printvec(const vec2 &v) {
	printf("# [%f %f]\n", v.x, v.y);
}

void printmat(const mat2 &m) {
	printvec(vec2(m.col1.x, m.col2.x));
	printvec(vec2(m.col1.y, m.col2.y));
}

int main () {
	mat2 A, B, I;
	vec2 a;

	I = mat2::identity();
	a = vec2(2, 4);
	test (a * I == a, "vec2 * mat2 (identity matrix)");
	test (I * a == a, "mat2 * vec2 (identity matrix)");
	A = mat2(vec2(1, 2), vec2(3, 4));
	B = mat2(vec2(5, 6), vec2(7, 8));
	test (A * B == mat2(vec2(19, 22), vec2(43, 50)), "mat2 * mat2");
	test (B * A == mat2(vec2(23, 34), vec2(31, 46)), "mat2 * mat2 (other order)");
	test (transpose(A) == mat2(vec2(1, 3), vec2(2, 4)), "transpose");
	test (invert(I) == I, "invert identity");
	A = mat2(1, 2, 3, 4);
	printmat(A);
	printmat(invert(A));
	test (invert(A) == mat2(-2, 1, 1.5, -.5), "invert");
	A = mat2(4, 5, 2, 9);
	test (A * invert(A) == I, "AA^-1 = I");
	done();
	return 0;
}
