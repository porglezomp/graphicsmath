#include "vec3.h"

#include "vec4.h"
#include "vec2.h"
#include "math.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

// Constructors
vec3::vec3() : x(0), y(0), z(0) { }
vec3::vec3(float v) : x(v), y(v), z(v) { }
vec3::vec3(float x, float y, float z) : x(x), y(y), z(z) { }

// Conversion constructors
vec3::vec3(const vec4 &v) : x(v.x), y(v.y), z(v.z) { }
vec3::vec3(const vec2 &v) : x(v.x), y(v.y), z(0) { }
vec3::vec3(const vec2 &v, float z) : x(v.x), y(v.y), z(z) { }
vec3::vec3(float x, const vec2 &v) : x(x), y(v.x), z(v.y) { }

// Element indexing
float& vec3::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on vec3"));
}

// Equality
bool operator== (const vec3 &a, const vec3 &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
bool operator!= (const vec3 &a, const vec3 &b) {
	return a.x != b.x || a.y != b.y || a.z != b.z;
}

// Addition
vec3& vec3::operator+= (const vec3 &v) {
	x += v.x; y += v.y; z += v.z;
	return *this;
}
vec3 operator+ (vec3 a, const vec3 &b) {
	return a += b;
}
// Explicit addition for mixed vec3/vec2 addition
// Without this, behavior would be somewhat unpredictable (could return either a vec3 or vec2)
vec3 operator+ (const vec3 &a, const vec2 &b) {
	return a + vec3(b);
}
vec3 operator+ (const vec2 &a, const vec3 &b) {
	return vec3(a) + b;
}

// Subtraction
vec3& vec3::operator-= (const vec3& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}
vec3 operator- (vec3 a, const vec3 &b) {
	return a -= b;
}
// Explicit subtraction for vec3 - vec2 & vec2 - vec3
vec3 operator- (const vec3 &a, const vec2 &b) {
	return a - vec3(b);
}
vec3 operator- (const vec2 &a, const vec3 &b) {
	return vec3(a) - b;
}

// Negation
vec3 operator- (const vec3 &v) {
	return vec3(-v.x, -v.y, -v.z);
}

// Componentwise vector multiplication
vec3& vec3::operator*= (const vec3 &v) {
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}
vec3 operator* (vec3 a, const vec3 &b) {
	return a *= b;
}

// Scalar multiplication of the vector
vec3& vec3::operator*= (const float s) {
	x *= s; y *= s; z *= s;
	return *this;
}
vec3 operator* (vec3 v, const float s) {
	return v *= s;
}
vec3 operator* (const float s, vec3 v) {
	return v *= s;
}

// Componentwise vector division
vec3& vec3::operator/= (const vec3 &v) {
	x /= v.x; y /= v.y; z /= v.z;
	return *this;
}
vec3 operator/ (vec3 a, const vec3 &b) {
	return a /= b;
}

// Scalar division of the vector
vec3& vec3::operator/= (const float s) {
	x /= s; y /= s; z /= s;
	return *this;
}
vec3 operator/ (vec3 v, const float s) {
	return v /= s;
}
vec3 operator/ (const float s, vec3 v) {
	return v /= s;
}

// Length of the vector
float vec3::length() {
	return sqrtf(x*x + y*y + z*z);
}
float length(const vec3 &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

vec3 normalize(const vec3 &v) {
	return v/length(v);
}

// Dot product
float dot(const vec3 &a, const vec3 &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Cross product
vec3 cross(const vec3 &lhs, const vec3& rhs) {
	return vec3(lhs.y*rhs.z - lhs.z*rhs.y,
				lhs.z*rhs.x - lhs.x*rhs.z,
				lhs.x*rhs.y - lhs.y*rhs.x);
}
