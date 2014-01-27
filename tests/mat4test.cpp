#include "mat4.h"
#include "vec4.h"
#include "mat3.h"
#include <stdio.h>
#include "math.h"

int main() {
	puts("1..11");
	mat4 A, B, C, I;
	vec4 a, c;
	I = mat4::identity();
	a = vec4(10);
	if (a * I != a) puts("not ok 1 - vec4 * mat4 (Identity matrix)");
	else puts("ok 1 - vec4 * mat4 (Identity matrix)");
	if (I * a != a) puts("not ok 2 - mat4 * vec4 (Identity matrix)");
	else puts("ok 2 - mat4 * vec4 (Identity matrix)");
	a = vec4(1, 2, 3, 4);
	A = mat4(vec4(1, 2, 3, 4),
			 vec4(0, 1, 0, 0),
			 vec4(0, 0, 1, 0),
			 vec4(0, 0, 0, 1));
	c = vec4(1, 4, 6, 8);
	if (a * A != c) puts("not ok 3 - vec4 * mat4");
	else puts("ok 3 - vec4 * mat4");
	c = vec4(30, 2, 3, 4);
	if (A * a != c) puts("not ok 4 - mat4 * vec4");
	else puts("ok 4 - mat4 * vec4");
	B = mat4(vec4(1, 5, 7, 6),
			 vec4(2, 4, 6, 7),
			 vec4(3, 2, 8, 1),
			 vec4(5, 7, 3, 4));
	C = mat4(vec4(34, 47, 55, 39),
			 vec4(2, 4, 6, 7),
			 vec4(3, 2, 8, 1),
			 vec4(5, 7, 3, 4));
	if (A * B != C) puts("not ok 5 - mat4 * mat4");
	else puts("ok 5 - mat4 * mat4");
	C = mat4(vec4(1, 7, 10, 10),
			 vec4(2, 8, 12, 15),
 			 vec4(3, 8, 17, 13),
			 vec4(5, 17, 18, 24));
	if (B * A != C) puts("not ok 6 - mat4 * mat4 (other order)");
	else puts("ok 6 - mat4 * mat4 (other order)");
	C = mat4(vec4(1, 2, 3, 5),
			 vec4(5, 4, 2, 7),
			 vec4(7, 6, 8, 3),
			 vec4(6, 7, 1, 4));
	if (transpose(B) != C) puts("not ok 7 - transpose");
	else puts("ok 7 - transpose");
	a = vec4(0, 0, 1, 1);
	const vec3 temp = vec3(0, 0, 1);
	if (a * mat4::rotationmatrix(14, temp) != a) puts("not ok 8 - rotation matrix parallel");
	else puts("ok 8 - rotation matrix parallel");
	if (dot(mat4::rotationmatrix(90, vec3(0, 1, 0)) * a, vec4(1, 0, 0, 1)) < 1) puts("not ok 9 - rotation matrix perpindicular");
	else puts("ok 9 - rotation matrix perpindicular");
	if (vec3(mat4::rotationmatrix(45, vec3(1, 1, 0)) * a) != vec3(.5, -.5, sqrtf(.5))) puts("not ok 10 - arbitrary rotation");
	else puts("ok 10 - arbitrary rotation");
	A = mat4::identity();
	if (invert(A) != A) puts("not ok 8 - invert identity");
	else puts("ok 8 - invert identity");
	return 0;
}
