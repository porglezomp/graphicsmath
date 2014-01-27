#include "vec2.h"
#include "mat2.h"
#include <stdio.h>

void printvec(const vec2 &v) {
	printf("[%f %f]\n", v.x, v.y);
}

void printmat(const mat2 &m) {
	printvec(vec2(m.col1.x, m.col2.x));
	printvec(vec2(m.col1.y, m.col2.y));
}

int main () {
	puts("1..6");
	mat2 I = mat2::identity();
	//puts("I");
	//printmat(I);
	vec2 a = vec2(2, 4);
	/*puts("a");
	printvec(a);
	puts("a * I");
	printvec(a * I);*/
	if (a * I != a) puts("not ok 1 - vec2 * mat2 (identity matrix)");
	else puts("ok 1 - vec2 * mat2 (identity matrix)");
	//puts("I * a");
	//printvec(I * a);
	if (I * a != a) puts("not ok 2 - mat2 * vec2 (identity matrix)");
	else puts("ok 2 - mat2 * vec2 (identity matrix)");
	mat2 A = mat2(vec2(1, 2), vec2(3, 4));
	//puts("A");
	//printmat(A);
	mat2 B = mat2(vec2(5, 6), vec2(7, 8));
	/*puts("B");
	printmat(B);
	puts("A * B");
	printmat(A * B);*/
	if (A * B != mat2(vec2(19, 22), vec2(43, 50))) puts("not ok 3 - mat2 * mat2");
	else puts("ok 3 - mat2 * mat2");
	//puts("B * A");
	//printmat(B * A);
	if (B * A != mat2(vec2(23, 34), vec2(31, 46))) puts("not ok 4 - mat2 * mat2 (other order)");
	else puts("ok 4 - mat2 * mat2 (other order)");
	/*puts("A");
	printmat(A);
	puts("A transpose");
	printmat(transpose(A));*/
	if (transpose(A) != mat2(vec2(1, 3), vec2(2, 4))) puts("not ok 5 - transpose");
	else puts("ok 5 - transpose");
	A = mat2::identity();
	if (invert(A) != A) puts("not ok 6 - basic inversion");
	else puts("ok 6 - basic inversion");
	return 0;
}
