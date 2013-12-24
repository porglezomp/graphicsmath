#include "vec2.h"
#include "math.h"
#include <stdexcept>
#include <string>

// Constructors
vec2::vec2() : x(0), y(0) { }
vec2::vec2(float v) : x(v), y(v) { }
vec2::vec2(float x, float y) : x(x), y(y) { }

// Element Indexing
float& vec2::operator[](const int i) {
	if (i == 0) return x;
	if (i == 1) return y;
	throw std::out_of_range(i + " out of range on vec4");
}

// Addition
vec2& vec2::operator+=(const vec2 &v) {
	x += v.x; y += v.y;
	return *this;
}
vec2 operator+(vec2 a, const vec2 &b) {
	return a += b;
}

// Subtraction
vec2& vec2::operator-=(const vec2& v) {
	x -= v.x; y -= v.y;
	return *this;
}
vec2 operator-(vec2 a, const vec2 &b) {
	return a -= b;
}

// Negation
vec2 vec2::operator-(const vec2 &v) {
	return vec2(-v.x, -v.y);
}

// Componentwise vector multiplication
vec2& vec2::operator*=(const vec2 &v) {
	x *= v.x; y *= v.y;
	return *this;
}
vec2 operator*(vec2 a, const vec2 &b) {
	return a += b;
}

// Scalar multiplication of the vector
vec2& vec2::operator*=(const float s) {
	x *= s; y *= s;
	return *this;
}
vec2 operator*(vec2 v, const float s) {
	return v *= s;
}
vec2 operator*(const float s, vec2 v) {
	return v *= s;
}

// Componentwise vector division
vec2& vec2::operator/=(const vec2 &v) {
	x /= v.x; y /= v.y;
	return *this;
}
vec2 operator/(vec2 a, const vec2 &b) {
	return a /= b;
}

// Scalar division of the vector
vec2& vec2::operator/=(const float s) {
	x /= s; y /= s;
	return *this;
}
vec2 operator/(vec2 v, const float s) {
	return v /= s;
}
vec2 operator/(const float s, vec2 v) {
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
