#include "mat3.h"
#include "vec3.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

// Constructors
mat3::mat3() : col1(0), col2(0), col3(0) { }
mat3::mat3(vec3 a, vec3 b, vec3 c) {
	col1 = vec3(a.x, b.x, c.x);
	col2 = vec3(a.y, b.y, c.y);
	col3 = vec3(a.z, b.z, c.z);
}
/*mat3::mat3(float v[]) {
	for (int i = 0; i < 4; ++i) {
		(*this)[i] = vec3(v[i*3], v[i*3+1], v[i*3+2]);
	}
}*/

// Create an identity matrix
mat3 mat3::identity() {
	return mat3(vec3(1, 0, 0),
				vec3(0, 1, 0),
				vec3(0, 0, 1));
}

// Column indexing
vec3& mat3::operator[](const int i) {
	switch (i) {
		case 0: return col1;
		case 1: return col2;
		case 2: return col3;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat3"));
}

// Matrix addition/subtraction
mat3& mat3::operator+= (const mat3 &b) {
	col1 += b.col1;
	col2 += b.col2;
	col3 += b.col3;
	return *this;
}
mat3 operator+ (mat3 a, const mat3 &b) {
	return a += b;
}
mat3& mat3::operator-= (const mat3 &b) {
	col1 -= b.col1;
	col2 -= b.col2;
	col3 -= b.col3;
	return *this;
}
mat3 operator- (mat3 a, const mat3 &b) {
	return a += b;
}

// Vector-matrix multiplication (and vice-versa)
vec3 operator* (vec3 a, mat3 &b) {
	vec3 v (dot(a, b.col1),
			dot(a, b.col2),
			dot(a, b.col3));
	return v;
}
vec3 operator* (mat3 &a, const vec3 &b) {
	vec3 c = 0;
	c += b * a.col1;
	c += b * a.col2;
	c += b * a.col3;
	return c;
}

// The matrix product
mat3& mat3::operator*= (const mat3 &m) {
	throw std::logic_error("NOT IMPLEMENTED HAHAHA");
}

mat3 operator* (mat3 a, mat3 &b) {
	return a *= b;
}

// Transpose
mat3 transpose(mat3 &m) {
	return mat3(m[0], m[1], m[2]);
}

// Transform matrices
mat3 mat3translation(float x, float y) {
	return mat3(vec3(0, 0, x),
				vec3(0, 0, y),
				vec3(0, 0, 0));
}
mat3 mat3scale(float x, float y, float z) {
	return mat3(vec3(x, 0, 0),
				vec3(0, y, 0),
				vec3(0, 0, z));
}

//mat3& mat3::rotate(float, float, float, float) {
//
//}
//mat3& mat3::rotate(float) {
//
//}
mat3& mat3::translate(float x, float y) {
	(*this) *= mat3translation(x, y);
	return (*this);
}
mat3& mat3::scale(float x, float y, float z) {
	(*this) *= mat3scale(x, y, z);
	return (*this);
}
