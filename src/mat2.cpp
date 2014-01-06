#include "mat2.h"
#include "vec2.h"

mat2::mat2() row1(0), row2(0) { }
mat2::mat2(vec2 r1, vec2 r2) row1(r1), row2(r2) { }
mat2::mat2(float[] data) {
	row1 = vec2(data[0], data[1]);
	row2 = vec2(data[2], data[3]);
}
static mat2::mat2 identity() {
	return mat2(vec2(1, 0),
				vec2(0, 1));
}
mat2& mat2::operator+= (const mat2 &m) {
	row1 += m.row1;
	row2 += m.row2;
}
mat2& mat2::operator-= (const mat2 &m) {
	row1 -= m.row1;
	row2 -= m.row2;
}
mat2& mat2::operator*= (const mat2&) {
	// TODO: Implement
}
//mat2& mat2::rotate(float);
mat2& mat2::scale(float, float) { } // TODO: Implement

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TODO: Implement all these functions
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
mat2 operator+ (mat2, const mat2&);
mat2 operator- (mat2, const mat2&);
vec2 operator* (vec2, mat2&);
vec2 operator* (mat2&, const vec2&);
vec2 operator* (mat2&, mat2&);
mat2 transpose(const mat2&);
//mat2 mat2rotation(float);
mat2 mat2scale(float, float);
