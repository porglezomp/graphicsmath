#include "mat2.h"
#include "vec2.h"
#include <stdexcept>
#include <string>

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
vec2& mat2::operator[] (const int i) {
	switch (i) {
		case 0: return col1;
		case 1: return col2;
	}
	std::out_of_range(std::to_string(i) + " out of range for operator[] in vec2");
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

vec2 mat2::row(const int i) {
	switch (i) {
		case 0: return vec2(col1.x, col2.x);
		case 1: return vec2(col1.y, col2.y);
	}
	std::out_of_range(std::to_string(i) + " out of range for row in vec2");
}

mat2 operator+ (mat2 a, const mat2 &b) {
	return a += b;
}

mat2 operator- (mat2 a, const mat2 &b) {
	return a -= b;
}

vec2 operator* (vec2 a, const mat2 &b) {
	return a *= b;
}

vec2 operator* (const mat2 &a, vec2 b) {
	return b *= transpose(a);
}

mat2 operator* (mat2 &a, mat2 &b) {
	return mat2(vec2(dot(a.row(0), b[0]),
					 dot(a.row(0), b[1])),
				vec2(dot(a.row(1), b[0]),
					 dot(a.row(1), b[1])));
}

mat2 transpose(const mat2 &m) {
	return mat2(m.col1, m.col2);
}

//mat2 mat2rotation(float);

mat2 mat2scale(float x, float y) {
	return mat2(vec2(x, 0),
				vec2(0, y));
}
