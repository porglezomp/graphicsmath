#include "vec3.h"
#include "mat3.h"
#include <stdio.h>


int main () {
	puts("1..7");
	mat3 A, B, C, I;
	vec3 a = vec3(1, 2, 3);
	I = mat3::identity();
	if (I != mat3(vec3(1, 0, 0), vec3(0, 1, 0), vec3(0, 0, 1))) puts("not ok 1 - identity matrix does not generate");
	else puts("ok 1 - identity matrix generates correctly");
	if (a * I != a) puts("not ok 2 - vec3 * mat3 (identity matrix)");
	else puts("ok 2 - vec3 * mat3 (identity matrix)");
	if (I * a != a) puts("not ok 3 - mat3 * vec3 (identity matrix)");
	else puts("ok 3 - mat3 * vec3 (identity matrix)");
	A = mat3(vec3(1, 2, 3),
			 vec3(4, 5, 6),
			 vec3(7, 8, 9));
	B = mat3(vec3(2, 4, 6),
			 vec3(1, 3, 5),
			 vec3(9, 8, 7));
	C = mat3(vec3(31,  34,  37),
			 vec3(67,  79,  91),
			 vec3(103, 124, 145));
	if (A * B != C) puts("not ok 4 - mat2 * mat2");
	else puts("ok 4 - mat2 * mat2");
	C = mat3(vec3(60, 72, 84),
			 vec3(48, 57, 66),
			 vec3(90, 114, 138));
	if (B * A != C) puts("not ok 5 - mat2 * mat2 (other order)");
	else puts("ok 5 - mat2 * mat2 (other order)");
	if (transpose(A) != mat3(vec3(1, 4, 7),
							 vec3(2, 5, 8),
							 vec3(3, 6, 9))) puts("not ok 6 - transpose");		  
	else puts("ok 6 - transpose");
	A = mat3::identity();
	if (invert(A) != A) puts("not ok 7 - invert identity");
	puts("ok 7 - invert identity");
	return 0;
}
