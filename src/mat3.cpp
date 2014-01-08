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
	throw std::out_of_range(errnum + std::string(" out of range for mat3[]"));
}

bool operator== (const mat3 &lhs, const mat3 &rhs) {
	return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2 && lhs.col3 == rhs.col3;
}
bool operator!= (const mat3 &lhs, const mat3 &rhs) {
	return lhs.col1 != rhs.col1 || lhs.col2 != rhs.col2 || lhs.col3 != rhs.col3;
}

vec3 mat3::col(const int i) const {
	switch (i) {
		case 0: return col1;
		case 1: return col2;
		case 2: return col3;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat3::col()"));
}
vec3 mat3::row(const int i) const {
	switch (i) {
		case 0: return vec3(col1.x, col2.x, col3.x);
		case 1: return vec3(col1.y, col2.y, col3.y);
		case 2: return vec3(col1.z, col2.z, col3.z);
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat3::row()"));
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
vec3 operator* (const vec3 &a, const mat3 &b) {
	return vec3(dot(a, b.col1),
				dot(a, b.col2),
				dot(a, b.col3));
}
vec3 operator* (const mat3 &a, const vec3 &b) {
	return b * transpose(a);
}

// The matrix product
mat3& mat3::operator*= (const mat3 &rhs) {
	mat3 lhs;
	for (int i = 0; i < 3; ++i) {
		lhs[i] = vec3(dot(row(0), rhs.col(i)), 
					  dot(row(1), rhs.col(i)),
					  dot(row(2), rhs.col(i)));
	}
	*this = lhs;
	return *this;
}

mat3 operator* (mat3 a, const mat3 &b) {
	return a *= b;
}

// Transpose
mat3 transpose(const mat3 &m) {
	return mat3(m.col(0), m.col(1), m.col(2));
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
