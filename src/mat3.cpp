#include "mat3.h"
#include "vec3.h"
#include "mat2.h"
#include "vec2.h"
#include "gm_exception.h"
#include <stdexcept>
#include <math.h>
#include <string>
#include <stdio.h>

#define PI	3.141592654
#define DEG2RAD	PI/180
#define RAD2DEG	180/PI


// ************
// Constructors
// ************

mat3::mat3() : col1(0), col2(0), col3(0) { }
mat3::mat3(vec3 a, vec3 b, vec3 c) {
	col1 = vec3(a.x, b.x, c.x);
	col2 = vec3(a.y, b.y, c.y);
	col3 = vec3(a.z, b.z, c.z);
}
mat3::mat3(float v[]) {
	col1 = vec3(v[0], v[3], v[6]);
	col2 = vec3(v[1], v[4], v[7]);
	col3 = vec3(v[2], v[5], v[8]);
}

// Create an identity matrix
mat3 mat3::identity() {
	return mat3(vec3(1, 0, 0),
				vec3(0, 1, 0),
				vec3(0, 0, 1));
}


// ***************************
// Various accessing functions
// ***************************

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

vec3 mat3::getCol(const int i) const {
	switch (i) {
		case 0: return col1;
		case 1: return col2;
		case 2: return col3;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat3::getCol()"));
}


vec3 mat3::getRow(const int i) const {
	switch (i) {
		case 0: return vec3(col1.x, col2.x, col3.x);
		case 1: return vec3(col1.y, col2.y, col3.y);
		case 2: return vec3(col1.z, col2.z, col3.z);
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range for mat3::getRow()"));
}

void mat3::setRow(const int i, const vec3& inRow){
	col1[i] = inRow.x;
	col2[i] = inRow.y;
	col3[i] = inRow.z;	
}

void mat3::setCol(const int i, const vec3& inCol){
	switch(i){
		case 0: 
			col1 = inCol;
			break;
		case 1:
			col2 = inCol;
			break;
		case 2:
			col3 = inCol;
			break;
	}
}


// ******************
// Equality operators
// ******************

bool operator== (const mat3 &lhs, const mat3 &rhs) {
	return lhs.col1 == rhs.col1 && lhs.col2 == rhs.col2 && lhs.col3 == rhs.col3;
}
bool operator!= (const mat3 &lhs, const mat3 &rhs) {
	return lhs.col1 != rhs.col1 || lhs.col2 != rhs.col2 || lhs.col3 != rhs.col3;
}


// ********************
// Arithmetic operators
// ********************

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
vec2 operator* (const vec2 &lhs, const mat3 &rhs) {
	return vec2(vec3(lhs, 1) * rhs);
}
vec2 operator* (const mat3 &lhs, const vec2 &rhs) {
	return vec2(lhs * vec3(rhs, 1));
}

// The matrix product
mat3& mat3::operator*= (const mat3 &rhs) {
	mat3 lhs;
	for (int i = 0; i < 3; ++i) {
		lhs[i] = vec3(dot(getRow(0), rhs.getCol(i)), 
					  dot(getRow(1), rhs.getCol(i)),
					  dot(getRow(2), rhs.getCol(i)));
	}
	*this = lhs;
	return *this;
}

mat3 operator* (mat3 a, const mat3 &b) {
	return a *= b;
}

mat3& mat3::operator*= (const float rhs){
	col1 *= rhs;
	col2 *= rhs;
	col3 *= rhs;
	return *this;
}

mat3 operator* (mat3& lhs, const float rhs){
	return lhs *= rhs;
}

mat3 operator* (const float lhs, mat3& rhs){
	return rhs *= lhs;
}

// Transpose
mat3 transpose(const mat3 &m) {
	return mat3(m.getCol(0), m.getCol(1), m.getCol(2));
}

// ********************************
// Generate transformation matrices
// ********************************

mat3 mat3::translationmatrix(float x, float y) {
	return mat3(vec3(0, 0, x),
				vec3(0, 0, y),
				vec3(0, 0, 0));
}

mat3 mat3::scalematrix(float x, float y, float z) {
	return mat3(vec3(x, 0, 0),
				vec3(0, y, 0),
				vec3(0, 0, z));
}

mat3 mat3::rotationmatrix(float theta) {
	float rad = theta*DEG2RAD;
	float co = cosf(rad);
	float si = sinf(rad);
	return mat3(vec3(co, -si, 0),
				vec3(si,  co, 0),
				vec3(0,   0,  0));
}

mat3 mat3::rotationmatrix(float theta, const vec3 &axis) {
	vec3 u = normalize(axis);
	theta *= DEG2RAD;
	double co = cos(theta), si = sin(theta);
	return mat3(vec3(co + u.x*u.x*(1 - co),   u.x*u.y*(1 - co) - u.z*si,   u.x*u.z*(1 - co) + u.y*si),
				vec3(u.y*u.x*(1 - co) + u.z*si,   co + u.y*u.y*(1 - co),   u.y*u.z*(1 - co) - u.x*si),
				vec3(u.z*u.x*(1 - co) - u.y*si,   u.z*u.y*(1 - co) + u.x*si,   co + u.z*u.z*(1 - co)));
}


// *********************************
// Functions that transform a matrix
// *********************************

mat3& mat3::rotate(float theta, const vec3 &axis) {
	*this *= mat3::rotationmatrix(theta);
	return *this;
}

mat3& mat3::rotate(float theta) {
	*this *= mat3::rotationmatrix(theta);
	return *this;
}

mat3& mat3::translate(float x, float y) {
	(*this) *= mat3::translationmatrix(x, y);
	return (*this);
}

mat3& mat3::scale(float x, float y, float z) {
	(*this) *= mat3::scalematrix(x, y, z);
	return (*this);
}
//calculate determinant of 3x3 matrix
float det(const mat3 &m){
	float ret = 0;
	ret += m.col1.x * det(mat2(vec2(m.col2.y, m.col2.z),
							vec2(m.col3.y, m.col3.z)));

	ret -= m.col2.x * det(mat2(vec2(m.col1.y, m.col1.z),
							vec2(m.col3.y, m.col3.z)));

	ret += m.col3.x * det(mat2(vec2(m.col1.y, m.col1.z),
							vec2(m.col2.y, m.col2.z)));
	return ret;
}

mat3 invert(const mat3& toInv){
	vec3 col1, col2, col3;
	vec3 row1 = toInv.getRow(0);
	vec3 row2 = toInv.getRow(1);
	vec3 row3 = toInv.getRow(2);
	col1 = vec3(det(mat2(vec2(row2[1], row2[2]), 
				vec2(row3[1], row3[2])))	,
				-1.0 * det(mat2(vec2(row1[1], row1[2]), 
				vec2(row3[1], row3[2]))),
				det(mat2(vec2(row1[1], row1[2]), 
				vec2(row2[1], row2[2]))));
	col2 = vec3(-1.0 * det(mat2(vec2(row2[0], row2[2]), 
				vec2(row3[0], row3[2]))),
				det(mat2(vec2(row1[0], row1[2]), 
				vec2(row3[0], row3[2]))),
				-1.0 * det(mat2(vec2(row1[0], row1[2]), 
				vec2(row2[0], row2[2]))));
	col3 = vec3(det(mat2(vec2(row2[0], row2[1]), 
				vec2(row3[0], row3[1]))),
				-1.0 * det(mat2(vec2(row1[0], row1[1]), 
				vec2(row3[0], row3[1]))),
				det(mat2(vec2(row1[0], row1[1]), 
				vec2(row2[0], row2[1]))));
	float determ = det(toInv);
	if (determ != 0){
		mat3 ret = mat3(col1, col2, col3);
		determ = (float) 1.0/determ;
		return  determ * ret;
	} else {
		throw singular_matrix();
	}
		
}
