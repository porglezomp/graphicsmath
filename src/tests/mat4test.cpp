#include "mat4.h"
#include "vec4.h"
#include <stdio.h>

void printvec(const vec4 &v) {
	printf("[%f %f %f %f]", v.x, v.y, v.z, v.w);
}

void printmat(const mat4 &m) {
	printvec(m.row1); puts("");
	printvec(m.row2); puts("");
	printvec(m.row3); puts("");
	printvec(m.row4);
}

int main() {
	puts("I");
	mat4 I = mat4::identity();
	printmat(I); puts("");
	vec4 a = vec4(10);
	puts("a");
	printvec(a); puts("");
	puts("a * I");
	printvec(a * I); puts("");
	if (a * I != a) return 1;
	puts("I * a");
	printvec(I * a); puts("");
	if (I * a != a) return 2;
	return 0;
}
