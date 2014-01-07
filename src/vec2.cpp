#include "vec2.h"

#include "vec4.h"
#include "vec3.h"
#include "mat2.h"
#include "math.h"
#include <stdexcept>
#include <string>

// Constructors
vec2::vec2() : x(0), y(0) { }
vec2::vec2(float v) : x(v), y(v) { }
vec2::vec2(float x, float y) : x(x), y(y) { }

// Conversion constructors
vec2::vec2(const vec4 &v) : x(v.x), y(v.y) { }
vec2::vec2(const vec3 &v) : x(v.x), y(v.y) { }

// Element indexing
float& vec2::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
	}
	throw std::out_of_range(std::to_string(i) + " out of range on vec4");
}

// Equality
bool operator== (const vec2 &a, const vec2 &b) {
	return a.x == b.x && a.y == b.y;
}
bool operator!= (const vec2 &a, const vec2 &b) {
	return a.x != b.x || a.y != b.y;
}

// Addition
vec2& vec2::operator+= (const vec2 &v) {
	x += v.x; y += v.y;
	return *this;
}
vec2 operator+ (vec2 a, const vec2 &b) {
	return a += b;
}

// Subtraction
vec2& vec2::operator-= (const vec2& v) {
	x -= v.x; y -= v.y;
	return *this;
}
vec2 operator- (vec2 a, const vec2 &b) {
	return a -= b;
}

// Negation
vec2 operator- (const vec2 &v) {
	return vec2(-v.x, -v.y);
}

// Componentwise vector multiplication
vec2& vec2::operator*= (const vec2 &v) {
	x *= v.x; y *= v.y;
	return *this;
}
vec2 operator* (vec2 a, const vec2 &b) {
	return a += b;
}

// Scalar multiplication of the vector
vec2& vec2::operator*= (const float s) {
	x *= s; y *= s;
	return *this;
}
vec2& vec2::operator*= (const mat2 rhs) {
	vec2 ret;
	ret.x = dot(lhs, rhs.col1);
	ret.y = dot(lhs, rhs.col2);
	return ret;
} 

vec2 operator* (vec2 v, const float s) {
	return v *= s;
}
vec2 operator* (const float s, vec2 v) {
	return v *= s;
}

// Multiply the vector by a matrix
vec2& vec2::operator*= (const mat2 &m) {
	*this = vec2(dot(*this, m.col1),
				dot(*this, m.col2));
	return *this;
}

// Componentwise vector division
vec2& vec2::operator/= (const vec2 &v) {
	x /= v.x; y /= v.y;
	return *this;
}
vec2 operator/ (vec2 a, const vec2 &b) {
	return a /= b;
}

// Scalar division of the vector
vec2& vec2::operator/= (const float s) {
	x /= s; y /= s;
	return *this;
}
vec2 operator/ (vec2 v, const float s) {
	return v /= s;
}
vec2 operator/ (const float s, vec2 v) {
	return v /= s;
}

// Length of the vector
float vec2::length() {
	return sqrtf(x*x + y*y);
}
float length(const vec2 &v) {
	return sqrtf(v.x*v.x + v.y*v.y);
}

// Dot product
float dot(const vec2 &a, const vec2 &b) {
	return a.x*b.x + a.y*b.y;
}
