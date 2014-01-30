#include "vec3.h"
#include "mat3.h"
#include "test.h"
#include <math.h>

void printmat(mat3 m) {
	printf("# [%f %f %f]\n# [%f %f %f]\n# [%f %f %f]\n",
					m[0][0], m[1][0], m[2][0],
					m[0][1], m[1][1], m[2][1],
					m[0][2], m[1][2], m[2][2]);
}

int main () {
	mat3 A, B, C, I;
	vec3 a = vec3(1, 2, 3);
	I = mat3::identity();
	test (I == mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1)), "identity matrix");
	test (a * I == a, "vec3 * mat3 (identity matrix)");
	test (I * a == a, "mat3 * vec3 (identity matrix)");
	A = mat3(vec3(1, 2, 3),
			 vec3(4, 5, 6),
			 vec3(7, 8, 9));
	B = mat3(vec3(2, 4, 6),
			 vec3(1, 3, 5),
			 vec3(9, 8, 7));
	C = mat3(vec3(31,  34,  37),
			 vec3(67,  79,  91),
			 vec3(103, 124, 145));
	test (A * B == C, "mat2 * mat2");
	C = mat3(vec3(60, 72, 84),
			 vec3(48, 57, 66),
			 vec3(90, 114, 138));
	test (B * A == C, "mat2 * mat2 (other order)");
	test (transpose(A) == mat3(vec3(1, 4, 7),
							   vec3(2, 5, 8),
							   vec3(3, 6, 9)),
							   "transpose");
	a = vec3(0, 0, 1);
	test (a * mat3::rotationmatrix(14, vec3(0, 0, 1)) == a, "rotation matrix parallel");
	test (dot(mat3::rotationmatrix(90, vec3(0, 1, 0)) * a, vec3(1, 0, 0)) == 1, "rotation matrix perpindicular");
	test (mat3::rotationmatrix(45, vec3(1, 1, 0)) * a == vec3(.5, -.5, sqrtf(.5)), "arbitrary rotation");
	test (invert(I) == I, "invert identity");
	A = mat3(vec3(1, 4, 2),
			 vec3(2, 3, 1),
			 vec3(3, 2, 5));
	printmat(invert(A));
	C = mat3(vec3(-.52, .64, .08),
			 vec3(.28, .04, -.12),
			 vec3(.2, -.4, .2));
	printmat(C);
	test (invert(A) == C, "invert");
	test (A * invert(A) == I, "AA^-1 = I");
	done();
	return 0;
}
