#include "vec4.h"

#include <math.h>
#include <stdio.h>
#include <stdexcept>
#include <string>

#include "vec3.h"
#include "vec2.h"

// Constructors
vec4::vec4() : x(0), y(0), z(0), w(0) { }
vec4::vec4(float v) : x(v), y(v), z(v), w(v) { }
vec4::vec4(float x, float y, float z, float w) :
			x(x), y(y), z(z), w(w) { }

// Conversion constructors
vec4::vec4(const vec3 &v) : x(v.x), y(v.y), z(v.z), w(0) { }
vec4::vec4(const vec3 &v, float w) : x(v.x), y(v.y), z(v.z), w(w) { }
vec4::vec4(float x, const vec3 &v) : x(x), y(v.x), z(v.y), w(v.z) { }
vec4::vec4(const vec2 &v) : x(v.x), y(v.y), z(0), w(0) { }
vec4::vec4(const vec2 &v, float z, float w) : x(v.x), y(v.y), z(z), w(w) { }
vec4::vec4(float x, const vec2 &v, float w) : x(x), y(v.x), z(v.y), w(w) { }
vec4::vec4(float x, float y, const vec2 &v) : x(x), y(y), z(v.x), w(v.y) { }

// Element indexing
float& vec4::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on vec4"));
}

// Equality
bool operator== (const vec4 &a, const vec4 &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}
bool operator!= (const vec4 &a, const vec4 &b) {
	return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
}

// Addition
vec4& vec4::operator+= (const vec4 &v) {
	x += v.x; y += v.y;
	z += v.z; w += v.w;
	return *this;
}
vec4 operator+ (vec4 a, const vec4 &b) {
	return a += b;
}
// Handle vec3 + vec4 and vec2 + vec4 explicitly
// Otherwise they can potentially have unpredictable results
vec4 operator+ (const vec4 &a, const vec3 &b) {
	return a + vec4(b);
}
vec4 operator+ (const vec3 &a, const vec4 &b) {
	return vec4(a) + b;
}
vec4 operator+ (const vec4 &a, const vec2 &b) {
	return a + vec4(b);
}
vec4 operator+ (const vec2 &a, const vec4 &b) {
	return vec4(a) + b;
}

// Subtraction
vec4& vec4::operator-= (const vec4& v) {
	x -= v.x; y -= v.y;
	z -= v.z; w -= v.w;
	return *this;
}
vec4 operator- (vec4 a, const vec4 &b) {
	return a -= b;
}
// Explicitly handle mixed type vector subtraction
vec4 operator- (const vec4 &a, const vec3 &b) {
	return a - vec4(b);
}
vec4 operator- (const vec3 &a, const vec4 &b) {
	return vec4(a) - b;
}
vec4 operator- (const vec4 &a, const vec2 &b) {
	return a - vec4(b);
}
vec4 operator- (const vec2 &a, const vec4 &b) {
	return vec4(a) - b;
}

// Negation
vec4 operator- (const vec4 &v) {
	return vec4(-v.x, -v.y, -v.z, -v.w);
}

// Componentwise vector multiplication
vec4& vec4::operator*= (const vec4 &v) {
	x *= v.x; y *= v.y;
	z *= v.z; w *= v.w;
	return *this;
}
vec4 operator* (vec4 a, const vec4 &b) {
	return a *= b;
}

// Scalar multiplication of the vector
vec4& vec4::operator*= (const float s) {
	x *= s; y *= s;
	z *= s; w *= s;
	return *this;
}
vec4 operator* (vec4 v, const float s) {
	return v *= s;
}
vec4 operator* (const float s, vec4 v) {
	return v *= s;
}

// Componentwise vector division
vec4& vec4::operator/= (const vec4 &v) {
	x /= v.x; y /= v.y;
	z /= v.z; w /= v.w;
	return *this;
}
vec4 operator/ (vec4 a, const vec4 &b) {
	return a /= b;
}

// Scalar division of the vector
vec4& vec4::operator/= (const float s) {
	x /= s; y /= s;
	z /= s; w /= s;
	return *this;
}
vec4 operator/ (vec4 v, const float s) {
	return v /= s;
}
vec4 operator/ (const float s, vec4 v) {
	return v /= s;
}

// Length of the vector
float vec4::length() {
	return sqrtf(x*x + y*y + z*z + w*w);
}
float length(const vec4 &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

vec4 normalize(const vec4 &v) {
	return v/length(v);
}

// Dot product
float dot(const vec4 &a, const vec4 &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}

vec4 lerp(const vec4 &a, const vec4 &b, float x) {
	return a + x*(b - a);
}