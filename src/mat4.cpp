#include "mat4.h"
#include "vec4.h"
#include <stdexcept>
#include <string>

// Constructors
mat4::mat4() : row1(0), row2(0), row3(0), row4(0) { }
mat4::mat4(vec4 a, vec4 b, vec4 c, vec4 d) :
			row1(a), row2(b), row3(c), row4(d) { }
mat4::mat4(float v[]) {
	for (int i = 0; i < 4; ++i) {
		(*this)[i] = vec4(v[i*4], v[i*4+1], v[i*4+2], v[i*4+3]);
	}
}

// Create an identity matrix
mat4 mat4::identity() {
	mat4 m;
	m.row1 = vec4(1, 0, 0, 0);
	m.row2 = vec4(0, 1, 0, 0);
	m.row3 = vec4(0, 0, 1, 0);
	m.row4 = vec4(0, 0, 0, 1);
	return m;
}

// Row indexing
vec4& mat4::operator[](const int i) {
	if (i == 0) return vec4(row1.x, row2.x, row3.x, row4.x);
	if (i == 1) return vec4(row1.y, row2.y, row3.y, row4.y);
	if (i == 2) return vec4(row1.z, row2.z, row3.z, row4.z);
	if (i == 3) return vec4(row1.w, row2.w, row3.w, row4.w);
	throw std::out_of_range(i + " out of range for mat4.");
}

// Matrix addition/subtraction
mat4& mat4::operator+= (const mat4 &b) {
	row1 += b.row1;
	row2 += b.row2;
	row3 += b.row3;
	row4 += b.row4;
	return *this;
}
mat4 operator+ (mat4 a, const mat4 &b) {
	return a += b;
}
mat4 mat4::operator-= (const mat4 &b) {
	row1 -= b.row1;
	row2 -= b.row2;
	row3 -= b.row3;
	row4 -= b.row4;
	return *this;
}
mat4 operator- (mat4 a, const mat4 &b) {
	return a += b;
}

// Vector-matrix multiplication (and vice-versa)
vec4 operator* (vec4 a, const mat4 &b) {
	a *= b.row1;
	a *= b.row2;
	a *= b.row3;
	a *= b.row4;
	return a;
}
vec4 operator* (const mat4 &a, const vec4 &b) {
	vec4 v = 0;
	v.x = dot(a, b.row1);
	v.y = dot(a, b.row2);
	v.z = dot(a, b.row3);
	v.w = dot(a, b.row4);
	return v;
}

// The matrix product
mat4& mat4::operator*= (const mat4 &m) {
	vec4 col1, col2, col3, col4;
	col1 = *this * m[0];
	col2 = *this * m[1];
	col3 = *this * m[2];
	col4 = *this * m[3];
	this->row1 = vec4(col1.x, col2.x, col3.x, col4.x);
	this->row2 = vec4(col1.y, col2.y, col3.y, col4.y);
	this->row3 = vec4(col1.z, col2.z, col3.z, col4.z);
	this->row4 = vec4(col1.w, col2.w, col3.w, col4.w);
	return *this;
}

mat4 operator* (mat4 a, const mat4 &b) {
	return a *= b;
}

// Transpose
mat4 transpose(const mat4 &m) {
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
