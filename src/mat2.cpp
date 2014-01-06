#include "mat2.h"
#include "vec2.h"

mat2::mat2() : col1(0), col2(0) { }
mat2::mat2(vec2 r1, vec2 r2) {
	col1 = vec2(r1.x, r2.x);
	col2 = vec2(r1.y, r2.y);
} 
mat2::mat2(float data[]) {
	col1 = vec2(data[0], data[2]);
	col2 = vec2(data[1], data[3]);
}
mat2 mat2::identity() {
	return mat2(vec2(1, 0),
				vec2(0, 1));
}
mat2& mat2::operator+= (const mat2 &m) {
	col1 += m.col1;
	col2 += m.col2;
	return *this;
}
mat2& mat2::operator-= (const mat2 &m) {
	col1 -= m.col1;
	col2 -= m.col2;
	return *this;
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
