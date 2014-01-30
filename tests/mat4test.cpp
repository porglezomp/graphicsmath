#include "mat4.h"
#include "vec4.h"
#include "mat3.h"
#include "test.h"
#include "math.h"

void printvec(const vec4 &v) {
	printf("# [%f %f %f %f]\n", v.x, v.y, v.z, v.w);
}

void printmat(const mat4 &m) {
	printvec(m.getRow(0));
	printvec(m.getRow(1));
	printvec(m.getRow(2));
	printvec(m.getRow(3));
}

int main() {
	mat4 A, B, C, I;
	vec4 a, c;
	I = mat4::identity();
	a = vec4(10);
	test (a * I == a, "vec4 * mat4 (Identity matrix)");
	test (I * a == a, "mat4 * vec4 (Identity matrix)");
	a = vec4(1, 2, 3, 4);
	A = mat4(vec4(1, 2, 3, 4),
			 vec4(0, 1, 0, 0),
			 vec4(0, 0, 1, 0),
			 vec4(0, 0, 0, 1));
	c = vec4(1, 4, 6, 8);
	test (a * A == c, "vec4 * mat4");
	c = vec4(30, 2, 3, 4);
	test (A * a == c, "mat4 * vec4");
	B = mat4(vec4(1, 5, 7, 6),
			 vec4(2, 4, 6, 7),
			 vec4(3, 2, 8, 1),
			 vec4(5, 7, 3, 4));
	C = mat4(vec4(34, 47, 55, 39),
			 vec4(2, 4, 6, 7),
			 vec4(3, 2, 8, 1),
			 vec4(5, 7, 3, 4));
	test (A * B == C, "mat4 * mat4");
	C = mat4(vec4(1, 7, 10, 10),
			 vec4(2, 8, 12, 15),
 			 vec4(3, 8, 17, 13),
			 vec4(5, 17, 18, 24));
	test (B * A == C, "mat4 * mat4 (other order)");
	C = mat4(vec4(1, 2, 3, 5),
			 vec4(5, 4, 2, 7),
			 vec4(7, 6, 8, 3),
			 vec4(6, 7, 1, 4));
	test (transpose(B) == C, "transpose");
	a = vec4(0, 0, 1, 1);
	const vec3 temp = vec3(0, 0, 1);
	test (a * mat4::rotationmatrix(14, temp) == a, "rotation matrix parallel");
	test (!(dot(mat4::rotationmatrix(90, vec3(0, 1, 0)) * a, vec4(1, 0, 0, 1)) < 1), "rotation matrix perpindicular");
	test (vec3(mat4::rotationmatrix(45, vec3(1, 1, 0)) * a) == vec3(.5, -.5, sqrtf(.5)), "arbitrary rotation");
	test (invert(I) == I, "invert identity");
	A = mat4(vec4(1, 0, 0, 0),
			 vec4(2, 1, 1, 0),
			 vec4(0, 2, 1, 0),
			 vec4(0, 3, 2, 1));
	puts("# A");
	printmat(A);
	C = mat4(vec4(1, 0, 0, 0),
			 vec4(2, -1, 1, 0),
			 vec4(-4, 2, -1, 0),
			 vec4(2, -1, -1, 1));
	puts("# Goal");
	printmat(C);
	puts("# A^-1");
	printmat(invert(A));
	test (invert(A) == C, "invert");
	test (A * invert(A) == I, "AA^-1 = I");
	done();
	return 0;
}
