#include "vec2t.h"
#include "vec3t.h"
#include "math.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

// Constructors
template <typename T>
vec4t<T>::vec4t() : x(0), y(0), z(0), w(0) { }
template <typename T>
vec4t<T>::vec4t(T v) : x(v), y(v), z(v), w(v) { }
template <typename T>
vec4t<T>::vec4t(T x, T y, T z, T w) :
			x(x), y(y), z(z), w(w) { }

// Conversion constructors
template <typename T>
vec4t<T>::vec4t(const vec3t<T> &v) : x(v.x), y(v.y), z(v.z), w(0) { }
template <typename T>
vec4t<T>::vec4t(const vec3t<T> &v, T w) : x(v.x), y(v.y), z(v.z), w(w) { }
template <typename T>
vec4t<T>::vec4t(T x, const vec3t<T> &v) : x(x), y(v.x), z(v.y), w(v.z) { }
template <typename T>
vec4t<T>::vec4t(const vec2t<T> &v) : x(v.x), y(v.y), z(0), w(0) { }
template <typename T>
vec4t<T>::vec4t(const vec2t<T> &v, T z, T w) : x(v.x), y(v.y), z(z), w(w) { }
template <typename T>
vec4t<T>::vec4t(T x, const vec2t<T> &v, T w) : x(x), y(v.x), z(v.y), w(w) { }
template <typename T>
vec4t<T>::vec4t(T x, T y, const vec2t<T> &v) : x(x), y(y), z(v.x), w(v.y) { }

// Element indexing
template <typename T>
T& vec4t<T>::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on vec4t<T>"));
}

// Equality
template <typename T>
bool operator== (const vec4t<T> &a, const vec4t<T> &b) {
	return a.x == b.x && a.y == b.y && a.z == b.z && a.w == b.w;
}
template <typename T>
bool operator!= (const vec4t<T> &a, const vec4t<T> &b) {
	return a.x != b.x || a.y != b.y || a.z != b.z || a.w != b.w;
}

// Addition
template <typename T>
vec4t<T>& vec4t<T>::operator+= (const vec4t<T> &v) {
	x += v.x; y += v.y;
	z += v.z; w += v.w;
	return *this;
}
template <typename T>
vec4t<T> operator+ (vec4t<T> a, const vec4t<T> &b) {
	return a += b;
}
// Handle vec3t<T> + vec4t<T> and vec2t<T> + vec4t<T> explicitly
// Otherwise they can potentially have unpredictable results
template <typename T>
vec4t<T> operator+ (const vec4t<T> &a, const vec3t<T> &b) {
	return a + vec4t<T>(b);
}
template <typename T>
vec4t<T> operator+ (const vec3t<T> &a, const vec4t<T> &b) {
	return vec4t<T>(a) + b;
}
template <typename T>
vec4t<T> operator+ (const vec4t<T> &a, const vec2t<T> &b) {
	return a + vec4t<T>(b);
}
template <typename T>
vec4t<T> operator+ (const vec2t<T> &a, const vec4t<T> &b) {
	return vec4t<T>(a) + b;
}

// Subtraction
template <typename T>
vec4t<T>& vec4t<T>::operator-= (const vec4t<T>& v) {
	x -= v.x; y -= v.y;
	z -= v.z; w -= v.w;
	return *this;
}
template <typename T>
vec4t<T> operator- (vec4t<T> a, const vec4t<T> &b) {
	return a -= b;
}
// Explicitly handle mixed type vector subtraction
template <typename T>
vec4t<T> operator- (const vec4t<T> &a, const vec3t<T> &b) {
	return a - vec4t<T>(b);
}
template <typename T>
vec4t<T> operator- (const vec3t<T> &a, const vec4t<T> &b) {
	return vec4t<T>(a) - b;
}
template <typename T>
vec4t<T> operator- (const vec4t<T> &a, const vec2t<T> &b) {
	return a - vec4t<T>(b);
}
template <typename T>
vec4t<T> operator- (const vec2t<T> &a, const vec4t<T> &b) {
	return vec4t<T>(a) - b;
}

// Negation
template <typename T>
vec4t<T> operator- (const vec4t<T> &v) {
	return vec4t<T>(-v.x, -v.y, -v.z, -v.w);
}

// Componentwise vector multiplication
template <typename T>
vec4t<T>& vec4t<T>::operator*= (const vec4t<T> &v) {
	x *= v.x; y *= v.y;
	z *= v.z; w *= v.w;
	return *this;
}
template <typename T>
vec4t<T> operator* (vec4t<T> a, const vec4t<T> &b) {
	return a *= b;
}

// Scalar multiplication of the vector
template <typename T>
vec4t<T>& vec4t<T>::operator*= (const T s) {
	x *= s; y *= s;
	z *= s; w *= s;
	return *this;
}
template <typename T>
vec4t<T> operator* (vec4t<T> v, const T s) {
	return v *= s;
}
template <typename T>
vec4t<T> operator* (const T s, vec4t<T> v) {
	return v *= s;
}

// Componentwise vector division
template <typename T>
vec4t<T>& vec4t<T>::operator/= (const vec4t<T> &v) {
	x /= v.x; y /= v.y;
	z /= v.z; w /= v.w;
	return *this;
}
template <typename T>
vec4t<T> operator/ (vec4t<T> a, const vec4t<T> &b) {
	return a /= b;
}

// Scalar division of the vector
template <typename T>
vec4t<T>& vec4t<T>::operator/= (const T s) {
	x /= s; y /= s;
	z /= s; w /= s;
	return *this;
}
template <typename T>
vec4t<T> operator/ (vec4t<T> v, const T s) {
	return v /= s;
}
template <typename T>
vec4t<T> operator/ (const T s, vec4t<T> v) {
	return v /= s;
}

// Length of the vector
template <typename T>
T vec4t<T>::length() {
	return sqrtf(x*x + y*y + z*z + w*w);
}
template <typename T>
T length(const vec4t<T> &v) {
	return sqrtf(v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w);
}

template <typename T>
vec4t<T> normalize(const vec4t<T> &v) {
	return v/length(v);
}

// Dot product
template <typename T>
T dot(const vec4t<T> &a, const vec4t<T> &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z + a.w*b.w;
}
