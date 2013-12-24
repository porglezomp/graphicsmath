#include "vec3.h"
#include "math.h"
#include <stdexcept>
#include <string>

// Constructors
vec3::vec3() : x(0), y(0), z(0) { }
vec3::vec3(float v) : x(v), y(v), z(v) { }
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) { }

// Element Indexing
float& vec3::operator[](const int i) {
	if (i == 0) return x;
	if (i == 1) return y;
	if (i == 2) return z;
	throw std::out_of_range(i + " out of range on vec4");
}

// Equality
bool operator==(const vec3 &a, const vec3 &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
bool operator!=(const vec3 &a, const vec3 &b) {
	return a.x != b.x || a.y != b.y || a.z != b.z;
}

// Addition
vec3& vec3::operator+=(const vec3 &v) {
	x += v.x; y += v.y; z += v.z;
	return *this;
}
vec3 operator+(vec3 a, const vec3 &b) {
	return a += b;
}

// Subtraction
vec3& vec3::operator-=(const vec3& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}
vec3 operator-(vec3 a, const vec3 &b) {
	return a -= b;
}

// Negation
vec3 vec3::operator-(const vec3 &v) {
	return vec3(-v.x, -v.y, -v.z);
}

// Componentwise vector multiplication
vec3& vec3::operator*=(const vec3 &v) {
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}
vec3 operator*(vec3 a, const vec3 &b) {
	return a += b;
}

// Scalar multiplication of the vector
vec3& vec3::operator*=(const float s) {
	x *= s; y *= s; z *= s;
	return *this;
}
vec3 operator*(vec3 v, const float s) {
	return v *= s;
}
vec3 operator*(const float s, vec3 v) {
	return v *= s;
}

// Componentwise vector division
vec3& vec3::operator/=(const vec3 &v) {
	x /= v.x; y /= v.y; z /= v.z;
	return *this;
}
vec3 operator/(vec3 a, const vec3 &b) {
	return a /= b;
}

// Scalar division of the vector
vec3& vec3::operator/=(const float s) {
	x /= s; y /= s; z /= s;
	return *this;
}
vec3 operator/(vec3 v, const float s) {
	return v /= s;
}
vec3 operator/(const float s, vec3 v) {
	return v /= s;
}

// Length of the vector
float vec3::length() {
	return sqrtf(x*x + y*y + z*z);
}
float length(const vec3 &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

// Dot product
float dot(const vec3 &a, const vec3 &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
