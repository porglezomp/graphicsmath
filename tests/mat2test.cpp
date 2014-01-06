#include "vec2.h"
#include "mat2.h"

int main () {
	mat2 I = mat2::identity();
	vec2 a = vec2(2, 4);
	if (a * I != a) return 1;
	if (I * a != a) return 2;
	mat2 A = mat2(vec2(1, 2), vec2(3, 4));
	mat2 B = mat2(vec2(5, 6), vec2(7, 8));
	if (A * B != mat2(vec2(19, 22), vec2(43, 5))) return 3;
	if (B * A != mat2(vec2(23, 34), vec2(31, 46))) return 4;
	return 0;
}