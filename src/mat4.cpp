#include "mat4.h"

#include <math.h>
#include <stdio.h>
#include <stdexcept>
#include <string>
#include <iostream>

#include "gm_exception.h"
#include "vec4.h"
#include "mat3.h"

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

vec4 mat4::getRow(const int i) const {
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
vec4 mat4::getCol(const int i) const {
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

void mat4::setCol(const int i, const vec4& set){
	switch(i) {
		case 0: col1 = set;
		case 1: col2 = set;
		case 2: col3 = set;
		case 3: col4 = set;
		default: 
			char errnum[32];
			sprintf(errnum, "%i", i);
			throw std::out_of_range(errnum + std::string(" out of range for mat4"));
	}

}
void mat4::setRow(const int i, const vec4& set){
	if (0 <= i && 4 > i){
		col1[i] = set.x;
		col2[i] = set.y;
		col3[i] = set.z;
		col4[i] = set.w;
	} else{
		char errnum[32];
		sprintf(errnum, "%i", i);
		throw std::out_of_range(errnum + std::string(" out of range for mat4"));
	}
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
		lhs[i] = vec4(dot(getRow(0), rhs.getCol(i)), 
					  dot(getRow(1), rhs.getCol(i)),
					  dot(getRow(2), rhs.getCol(i)),
					  dot(getRow(3), rhs.getCol(i)));
	}
	*this = lhs;
	return *this;
}

mat4& mat4::operator*= (const float rhs){
	col1 *= rhs;
	col2 *= rhs;
	col3 *= rhs;
	col4 *= rhs;
	return *this;
}

mat4 operator* (mat4 a, const mat4 &b) {
	return a *= b;
}

mat4 operator* (mat4 lhs, const float rhs){
	return lhs *= rhs;
}

mat4 operator* (const float lhs, mat4 rhs){
	return rhs *= lhs;
}
// Transpose
mat4 transpose(const mat4 &m) {
	return mat4(m.col1, m.col2, m.col3, m.col4);
}


// ********************************
// Generate transformation matrices
// ********************************

mat4 mat4::rotationmatrix(float theta, const vec3 &axis) {
	mat3 m3 = mat3::rotationmatrix(theta, axis);
	return mat4(vec4(m3.getRow(0), 0),
				vec4(m3.getRow(1), 0), 
				vec4(m3.getRow(2), 0), 
				vec4(0, 0, 0, 1));
}

mat4 mat4::translationmatrix(float x, float y, float z) {
	return mat4(vec4(0, 0, 0, x),
				vec4(0, 0, 0, y),
				vec4(0, 0, 0, z),
				vec4(0, 0, 0, 1));
}

mat4 mat4::scalematrix(float x, float y, float z) {
	return mat4(vec4(x, 0, 0, 0),
				vec4(0, y, 0, 0),
				vec4(0, 0, z, 0),
				vec4(0, 0, 0, 1));
}


// ******************
// Transform a matrix
// ******************

mat4& mat4::rotate(float theta, const vec3 &axis) {
	*this *= mat4::rotationmatrix(theta, axis);
	return *this;
}
mat4& mat4::translate(float x, float y, float z) {
	(*this) *= mat4::translationmatrix(x, y, z);
	return (*this);
}
mat4& mat4::scale(float x, float y, float z) {
	(*this) *= mat4::scalematrix(x, y, z);
	return (*this);
}

// TODO: Invert function broken, will crash.
mat4 invert(const mat4& toInv){
	vec4 cols[4];
	vec4 row1 = toInv.getRow(0);
	vec4 row2 = toInv.getRow(1);
	vec4 row3 = toInv.getRow(2);
	vec4 row4 = toInv.getRow(3);
	//Create columns 
	for (int i = 0; i < 4; i++){
		int inds[3];
		int ct = 0;
		//find which column must be ommitted
		for (int j = 0; j < 4; j++){
			if (j!=i){
				// FIXME: Sometimes the index doesn't get initialized, causes an exception
				inds[ct] = j;
				ct += 1;
			}		
		}
		//Following defines the cofactor matrix as the componentwise multiplication of
		//the coefficient matrix and the matrix of minors.

		//all cols will have identical ommitted rows for minors.
		cols[i] = vec4(pow(-1.0, i) * det(mat3(vec3(row2[inds[0]], row2[inds[1]], row2[inds[2]]),
							 				   vec3(row3[inds[0]], row3[inds[1]], row3[inds[2]]),
							 				   vec3(row4[inds[0]], row4[inds[1]], row4[inds[2]]))),
					   pow(-1, i+1) * det(mat3(vec3(row1[inds[0]], row1[inds[1]], row1[inds[2]]),
							 				 vec3(row3[inds[0]], row3[inds[1]], row3[inds[2]]),
							 			 	 vec3(row4[inds[0]], row4[inds[1]], row4[inds[2]]))),
					   pow(-1, i) * det(mat3(vec3(row1[inds[0]], row1[inds[1]], row1[inds[2]]),
							 				   vec3(row2[inds[0]], row2[inds[1]], row2[inds[2]]),
							 				   vec3(row4[inds[0]], row4[inds[1]], row4[inds[2]]))),
					   pow(-1, i+1) * det(mat3(vec3(row1[inds[0]], row1[inds[1]], row1[inds[2]]),
							 				 vec3(row2[inds[0]], row2[inds[1]], row2[inds[2]]),
							 				 vec3(row3[inds[0]], row3[inds[1]], row3[inds[2]]))));
	}
	float determ = det(toInv);
	if (determ != 0){
		return (1.0/determ) * mat4(cols[0], cols[1], cols[2], cols[3]);
	} else {
		throw singular_matrix();
	}
}

float det(const mat4& toDet){
	float ret = 0;
	vec4 col1(toDet.col1), col2(toDet.col2), col3(toDet.col3), col4(toDet.col4);
	ret += col1[0] * det(mat3(vec3(col2[1], col2[2], col2[3]),
							  vec3(col3[1], col3[2], col3[3]),
							  vec3(col4[1], col4[2], col4[3])));
	ret -= col2[0] * det(mat3(vec3(col1[1], col1[2], col1[3]),
							  vec3(col3[1], col3[2], col3[3]),
							  vec3(col4[1], col4[2], col4[3])));
	ret += col3[0] * det(mat3(vec3(col1[1], col1[2], col1[3]),
							  vec3(col2[1], col2[2], col2[3]),
							  vec3(col4[1], col4[2], col4[3])));
	ret -= col4[0] * det(mat3(vec3(col1[1], col1[2], col1[3]),
							  vec3(col2[1], col2[2], col2[3]),							  
							  vec3(col3[1], col3[2], col3[3])));
	return ret;
}
