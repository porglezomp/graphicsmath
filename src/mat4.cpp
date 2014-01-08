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

bool operator== (const mat4 &lhs, const mat4 &rhs) {
	return lhs.col1 == rhs.col1 &&
		   lhs.col2 == rhs.col2 &&
		   lhs.col3 == rhs.col3 &&
		   lhs.col4 == rhs.col4;
}
bool operator!= (const mat4 &lhs, const mat4 &rhs) {
	return lhs.col1 != rhs.col1 ||
		   lhs.col2 != rhs.col2 ||
		   lhs.col3 != rhs.col3 ||
		   lhs.col4 != rhs.col4;
}

vec4 mat4::row(const int i) const {
	switch (i) {
		case 0: return vec4(col1.x, col2.x, col3.x, col4.x);
		case 1: return vec4(col1.y, col2.y, col3.y, col4.y);
		case 2: return vec4(col1.z, col2.z, col3.z, col4.z);
		case 3: return vec4(col1.w, col2.w, col3.w, col4.w);
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat4"));
}
vec4 mat4::col(const int i) const {
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
vec4 operator* (const vec4 &a, const mat4 &b) {
	return vec4(dot(a, b.col1),
				dot(a, b.col2),
				dot(a, b.col3),
				dot(a, b.col4));
}
vec4 operator* (const mat4 &a, const vec4 &b) {
	return b * transpose(a);
}

// The matrix product
mat4& mat4::operator*= (const mat4 &rhs) {
	mat4 lhs;
	for (int i = 0; i < 4; ++i) {
		lhs[i] = vec4(dot(row(0), rhs.col(i)), 
					  dot(row(1), rhs.col(i)),
					  dot(row(2), rhs.col(i)),
					  dot(row(3), rhs.col(i)));
	}
	*this = lhs;
	return *this;
}

mat4 operator* (mat4 a, const mat4 &b) {
	return a *= b;
}

// Transpose
mat4 transpose(const mat4 &m) {
	return mat4(m.col1, m.col2, m.col3, m.col4);
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
