#include "mat4.h"
#include "vec4.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

// Constructors
mat4::mat4() : col1(0), col2(0), col3(0), col4(0) { }
mat4::mat4(vec4 a, vec4 b, vec4 c, vec4 d) {
	col1 = vec4(a.x, b.x, c.x, d.x);
	col2 = vec4(a.y, b.y, c.y, d.y);
	col3 = vec4(a.z, b.z, c.z, d.z);
	col4 = vec4(a.w, b.w, c.w, d.w);
}
/*mat4::mat4(float v[]) {
	for (int i = 0; i < 4; ++i) {
		(*this)[i] = vec4(v[i*4], v[i*4+1], v[i*4+2], v[i*4+3]);
	}
}*/

// Create an identity matrix
mat4 mat4::identity() {
	return mat4(vec4(1, 0, 0, 0),
				vec4(0, 1, 0, 0),
				vec4(0, 0, 1, 0),
				vec4(0, 0, 0, 1));
}

// Column indexing
vec4& mat4::operator[](const int i) {
	switch (i) {
		case 0: return col1;
		case 1: return col2;
		case 2: return col3;
		case 3: return col4;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat4"));
}

// Matrix addition/subtraction
mat4& mat4::operator+= (const mat4 &b) {
	col1 += b.col1;
	col2 += b.col2;
	col3 += b.col3;
	col4 += b.col4;
	return *this;
}
mat4 operator+ (mat4 a, const mat4 &b) {
	return a += b;
}
mat4& mat4::operator-= (const mat4 &b) {
	col1 -= b.col1;
	col2 -= b.col2;
	col3 -= b.col3;
	col4 -= b.col4;
	return *this;
}
mat4 operator- (mat4 a, const mat4 &b) {
	return a += b;
}

// Vector-matrix multiplication (and vice-versa)
vec4 operator* (vec4 a, mat4 &b) {
	vec4 v (dot(a, b.col1),
			dot(a, b.col2),
			dot(a, b.col3),
			dot(a, b.col4));
	return v;
}
vec4 operator* (mat4 &a, const vec4 &b) {
	vec4 c = 0;
	c += b * a.col1;
	c += b * a.col2;
	c += b * a.col3;
	c += b * a.col4;
	return c;
}

// The matrix product
mat4& mat4::operator*= (const mat4 &m) {
	
}

mat4 operator* (mat4 a, mat4 &b) {
	return a *= b;
}

// Transpose
mat4 transpose(mat4 &m) {
	return mat4(m[0], m[1], m[2], m[3]);
}

// Transform matrices
mat4 mat4translation(float x, float y, float z) {
	return mat4(vec4(0, 0, 0, x),
				vec4(0, 0, 0, y),
				vec4(0, 0, 0, z),
				vec4(0, 0, 0, 1));
}
mat4 mat4scale(float x, float y, float z) {
	return mat4(vec4(x, 0, 0, 0),
				vec4(0, y, 0, 0),
				vec4(0, 0, z, 0),
				vec4(0, 0, 0, 1));
}

//mat4& mat4::rotate(float, float, float, float) {
//
//}
mat4& mat4::translate(float x, float y, float z) {
	(*this) *= mat4translation(x, y, z);
	return (*this);
}
mat4& mat4::scale(float x, float y, float z) {
	(*this) *= mat4scale(x, y, z);
	return (*this);
}
