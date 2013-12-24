#include "vec4.h"
#include "math.h"
#include <stdexcept>
#include <string>

// Constructors
vec4::vec4() : x(0), y(0), z(0), w(0) { }
vec4::vec4(float v) : x(v), y(v), z(v), w(v) { }
vec4::vec4(float x, float y, float z, float w) :
			x(x), y(y), z(z), w(w) { }

// Element Indexing
float& vec4::operator[](const int i) {
	if (i == 0) return x;
	if (i == 1) return y;
	if (i == 2) return z;
	if (i == 3) return w;
	throw std::out_of_range(i + " out of range on vec4");
}

// Addition
vec4& vec4::operator+=(const vec4 &v) {
	x += v.x; y += v.y;
	z += v.z; w += v.w;
	return *this;
}
vec4 operator+(vec4 a, const vec4 &b) {
	return a += b;
}

// Subtraction
vec4& vec4::operator-=(const vec4& v) {
	x -= v.x; y -= v.y;
	z -= v.z; w -= v.w;
	return *this;
}
vec4 operator-(vec4 a, const vec4 &b) {
	return a -= b;
}

// Negation
vec4 vec4::operator-(const vec4 &v) {
	return vec4(-v.x, -v.y, -v.z, -v.w);
}

// Componentwise vector multiplication
vec4& vec4::operator*=(const vec4 &v) {
	x *= v.x; y *= v.y;
	z *= v.z; w *= v.w;
	return *this;
}
vec4 operator*(vec4 a, const vec4 &b) {
	return a += b;
}

// Scalar multiplication of the vector
vec4& vec4::operator*=(const float s) {
	x *= s; y *= s;
	z *= s; w *= s;
	return *this;
}
vec4 operator*(vec4 v, const float s) {
	return v *= s;
}
vec4 operator*(const float s, vec4 v) {
	return v *= s;
}

// Componentwise vector division
vec4& vec4::operator/=(const vec4 &v) {
	x /= v.x; y /= v.y;
	z /= v.z; w /= v.w;
	return *this;
}
vec4 operator/(vec4 a, const vec4 &b) {
	return a /= b;
}

// Scalar division of the vector
vec4& vec4::operator/=(const float s) {
	x /= s; y /= s;
	z /= s; w /= s;
	return *this;
}
vec4 operator/(vec4 v, const float s) {
	return v /= s;
}
vec4 operator/(const float s, vec4 v) {
	return v /= s;
}

// Length of the vector
float vec4::length() {
	return sqrtf(x*x + y*y + z*z + w*w);
}
float length(const vec4 &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

// Dot product
float dot(const vec4 &a, const vec4 &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}
