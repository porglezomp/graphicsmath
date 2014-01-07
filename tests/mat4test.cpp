#include "mat4.h"
#include "vec4.h"
#include <stdio.h>

void printvec(const vec4 &v) {
	printf("[%f %f %f %f]\n", v.x, v.y, v.z, v.w);
}

void printmat(const mat4 &m) {
	/*printvec(m.row1);
	printvec(m.row2);
	printvec(m.row3);
	printvec(m.row4);*/
}

int main() {
// Try multiplying a vector both ways by the identity
	puts("I");
	mat4 I = mat4::identity();
	printmat(I);
	vec4 a = vec4(10);
	puts("a");
	printvec(a);

	puts("a * I");
	printvec(a * I);
	if (a * I != a) return 1;

	puts("I * a");
	printvec(I * a);
	if (I * a != a) return 2;

// Try multiplying a vector both ways by a different matrix
	a = vec4(1, 2, 3, 4);
	vec4 c;
	puts("");
	mat4 A = I;
	//A.row1 = vec4(1, 2, 3, 4);
	puts("A");
	printmat(A);

	c = vec4(3, 7, 10, 8);
	puts("c");
	printvec(c);
	puts("a * A");
	printvec(a * A);
	if (a * A != c) return 4;

	c = vec4(30, 2, 3, 4);
	puts("c");
	printvec(c);
	puts("A * a");
	printvec(A * a);
	if (A * a != c) return 3;

// Done
	return 0;
}
