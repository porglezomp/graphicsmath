#include "mat2.h"
#include "vec2.h"
#include "gm_exception.h"
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
mat2& mat2::operator*= (const mat2& rhs) {
	mat2 ret, transp;
	float a, b, c, d; 
	transp = transpose(*this)
	a = dot(transp.col1, rhs.col1);
	b = dot(transp.col1, rhs.col2);
	c = dot(transp.col2, rhs.col1);
	d = dot(transp.col2, rhs.col2);
	ret.col1 = vec2(a, c);
	ret.col2 = vec3(b, d);
	return ret
}
mat2& mat2::operator*= (const float rhs){
	mat2 ret;
	ret.col1 = vec2(col1.x * rhs, col1.y * rhs);
	ret.col2 = vec2(col2.x * rhs, col2.y * rhs);
	return ret;
}
//mat2& mat2::rotate(float);
mat2& mat2::scale(float, float) { } // TODO: Implement

/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TODO: Implement all these functions
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

mat2 operator+ (const mat2 lhs, const mat2& rhs){
	return lhs += rhs;
}

mat2 operator- (const mat2 lhs, const mat2& rhs){
	return lhs -= rhs;
}

vec2 operator* (const vec2 lhs, mat2& rhs){
	return lhs *= rhs;
}

vec2 operator* (const mat2 lhs, const vec2& rhs){
	return rhs *= transpose(lhs);
}

mat2 operator* (const mat2& lhs, const mat2& rhs){
	return lhs *= rhs;
}

mat2 operator* (const mat2& lhs, const float rhs){
	return lhs *= rhs;
}
mat2 operator* (const float lhs, const mat2& rhs){
	return rhs *= lhs;
}

float det(const mat2& toDet){
	float ret;
	float ret = toDet.col1.x * toDet.col2.y;
	float ret -= toDet.col1.y * toDet.col2.x;
	return ret;
}

mat2 invert(const mat2& toInvert){
	float determinant = det(toInvert);
	if (determinant == 0){
		throw SingularException();
	}
	return (1/determinant) * toInvert;
}

mat2 transpose(const mat2& toTransp){
	mat2 ret;
	ret.col1 = vec2(toTransp.col1.x, toTransp.col2.x);
	ret.col2 = vec2(toTransp.col1.y, toTransp.col2.y);
	return ret;
}
//mat2 mat2rotation(float);
mat2 mat2scale(float, float);
