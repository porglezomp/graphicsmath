//#include "vec4.h"
#include "vec2t.h"
#include "math.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

// Constructors
template <typename T>
vec3t<T>::vec3t() : x(0), y(0), z(0) { }
template <typename T>
vec3t<T>::vec3t(T v) : x(v), y(v), z(v) { }
template <typename T>
vec3t<T>::vec3t(T x, T y, T z) : x(x), y(y), z(z) { }

template <typename T>
vec3t<T>::vec3t(const vec3t<T> &v) : x(v.x), y(v.y), z(v.z) { }
template <typename T> template <typename U>
vec3t<T>::vec3t(const vec3t<U> &v) : x(v.x), y(v.y), z(v.z) { }

// Conversion constructors
//template <typename T>
//vec3t<T>::vec3t(const vec4 &v) : x(v.x), y(v.y), z(v.z) { }
template <typename T> template <typename U>
vec3t<T>::vec3t(const vec2t<U> &v) : x(v.x), y(v.y), z(0) { }
template <typename T>
vec3t<T>::vec3t(const vec2t<T> &v, T z) : x(v.x), y(v.y), z(z) { }
template <typename T>
vec3t<T>::vec3t(T x, const vec2t<T> &v) : x(x), y(v.x), z(v.y) { }

// Element indexing
template <typename T>
T& vec3t<T>::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on vec3t<T>"));
}

// Equality
template <typename T>
bool operator== (const vec3t<T> &a, const vec3t<T> &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z;
}
template <typename T>
bool operator!= (const vec3t<T> &a, const vec3t<T> &b) {
	return a.x != b.x || a.y != b.y || a.z != b.z;
}

// Addition
template <typename T>
vec3t<T>& vec3t<T>::operator+= (const vec3t<T> &v) {
	x += v.x; y += v.y; z += v.z;
	return *this;
}
template <typename T>
vec3t<T> operator+ (vec3t<T> a, const vec3t<T> &b) {
	return a += b;
}
// Explicit addition for mixed vec3t<T>/vec2 addition
// Without this, behavior would be somewhat unpredictable (could return either a vec3t<T> or vec2)
template <typename T>
vec3t<T> operator+ (const vec3t<T> &a, const vec2 &b) {
	return a + vec3t<T>(b);
}
template <typename T>
vec3t<T> operator+ (const vec2 &a, const vec3t<T> &b) {
	return vec3t<T>(a) + b;
}

// Subtraction
template <typename T>
vec3t<T>& vec3t<T>::operator-= (const vec3t<T>& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}
template <typename T>
vec3t<T> operator- (vec3t<T> a, const vec3t<T> &b) {
	return a -= b;
}
// Explicit subtraction for vec3t<T> - vec2 & vec2 - vec3t<T>
template <typename T>
vec3t<T> operator- (const vec3t<T> &a, const vec2 &b) {
	return a - vec3t<T>(b);
}
template <typename T>
vec3t<T> operator- (const vec2 &a, const vec3t<T> &b) {
	return vec3t<T>(a) - b;
}

// Negation
template <typename T>
vec3t<T> operator- (const vec3t<T> &v) {
	return vec3t<T>(-v.x, -v.y, -v.z);
}

// Componentwise vector multiplication
template <typename T>
vec3t<T>& vec3t<T>::operator*= (const vec3t<T> &v) {
	x *= v.x; y *= v.y; z *= v.z;
	return *this;
}
template <typename T>
vec3t<T> operator* (vec3t<T> a, const vec3t<T> &b) {
	return a += b;
}

// Scalar multiplication of the vector
template <typename T>
vec3t<T>& vec3t<T>::operator*= (const T s) {
	x *= s; y *= s; z *= s;
	return *this;
}
template <typename T>
vec3t<T> operator* (vec3t<T> v, const T s) {
	return v *= s;
}
template <typename T>
vec3t<T> operator* (const T s, vec3t<T> v) {
	return v *= s;
}

// Componentwise vector division
template <typename T>
vec3t<T>& vec3t<T>::operator/= (const vec3t<T> &v) {
	x /= v.x; y /= v.y; z /= v.z;
	return *this;
}
template <typename T>
vec3t<T> operator/ (vec3t<T> a, const vec3t<T> &b) {
	return a /= b;
}

// Scalar division of the vector
template <typename T>
vec3t<T>& vec3t<T>::operator/= (const T s) {
	x /= s; y /= s; z /= s;
	return *this;
}
template <typename T>
vec3t<T> operator/ (vec3t<T> v, const T s) {
	return v /= s;
}
template <typename T>
vec3t<T> operator/ (const T s, vec3t<T> v) {
	return v /= s;
}

// Length of the vector
template <typename T>
T vec3t<T>::length() {
	return sqrtf(x*x + y*y + z*z);
}
template <typename T>
T length(const vec3t<T> &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z);
}

template <typename T>
vec3t<T> normalize(const vec3t<T> &v) {
	return v/length(v);
}

// Dot product
template <typename T>
T dot(const vec3t<T> &a, const vec3t<T> &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}

// Cross product
template <typename T>
vec3t<T> cross(const vec3t<T> &lhs, const vec3t<T>& rhs) {
	return vec3t<T>(lhs.y*rhs.z - lhs.z*rhs.y,
				lhs.z*rhs.x - lhs.x*rhs.z,
				lhs.x*rhs.y - lhs.y*rhs.x);
}
