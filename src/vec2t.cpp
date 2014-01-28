//#include "vec4.h"
//#include "vec3.h"
//#include "mat2.h"
#include "math.h"
#include <stdexcept>
#include <string>
#include <stdio.h>

#define PI	3.141592654
#define RAD2DEG	180/PI
#define DEG2RAD	PI/180

// Constructors
template <typename T>
vec2t<T>::vec2t() : x(0), y(0) { }
template <typename T>
vec2t<T>::vec2t(T v) : x(v), y(v) { }
template <typename T>
vec2t<T>::vec2t(T x, T y) : x(x), y(y) { }

// Conversion constructors
//vec2t<T>::vec2t(const vec4 &v) : x(v.x), y(v.y) { }
//vec2t<T>::vec2t(const vec3 &v) : x(v.x), y(v.y) { }

// Element indexing
template <typename T>
T& vec2t<T>::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on vec4"));
}

// Equality
template <typename T>
bool operator== (const vec2t<T> &a, const vec2t<T> &b) {
	return a.x == b.x && a.y == b.y;
}
template <typename T>
bool operator!= (const vec2t<T> &a, const vec2t<T> &b) {
	return a.x != b.x || a.y != b.y;
}

// Addition
template <typename T>
vec2t<T>& vec2t<T>::operator+= (const vec2t<T> &v) {
	x += v.x; y += v.y;
	return *this;
}
template <typename T>
vec2t<T> operator+ (vec2t<T> a, const vec2t<T> &b) {
	return a += b;
}

// Subtraction
template <typename T>
vec2t<T>& vec2t<T>::operator-= (const vec2t<T>& v) {
	x -= v.x; y -= v.y;
	return *this;
}
template <typename T>
vec2t<T> operator- (vec2t<T> a, const vec2t<T> &b) {
	return a -= b;
}

// Negation
template <typename T>
vec2t<T> operator- (const vec2t<T> &v) {
	return vec2t<T>(-v.x, -v.y);
}

// Componentwise vector multiplication
template <typename T>
vec2t<T>& vec2t<T>::operator*= (const vec2t<T> &v) {
	x *= v.x; y *= v.y;
	return *this;
}
template <typename T>
vec2t<T> operator* (vec2t<T> a, const vec2t<T> &b) {
	return a += b;
}

// Scalar multiplication of the vector
template <typename T>
vec2t<T>& vec2t<T>::operator*= (const T s) {
	x *= s; y *= s;
	return *this;
}

template <typename T>
vec2t<T> operator* (vec2t<T> v, const T s) {
	return v *= s;
}
template <typename T>
vec2t<T> operator* (const T s, vec2t<T> v) {
	return v *= s;
}

/*
// Multiply the vector by a matrix
vec2t<T>& vec2t<T>::operator*= (const mat2 &m) {
	*this = vec2t<T>(dot(*this, m.col1),
				dot(*this, m.col2));
	return *this;
}
*/

// Componentwise vector division
template <typename T>
vec2t<T>& vec2t<T>::operator/= (const vec2t<T> &v) {
	x /= v.x; y /= v.y;
	return *this;
}
template <typename T>
vec2t<T> operator/ (vec2t<T> a, const vec2t<T> &b) {
	return a /= b;
}

// Scalar division of the vector
template <typename T>
vec2t<T>& vec2t<T>::operator/= (const T s) {
	x /= s; y /= s;
	return *this;
}
template <typename T>
vec2t<T> operator/ (vec2t<T> v, const T s) {
	return v /= s;
}

// Length of the vector
template <typename T>
T vec2t<T>::length() {
	return sqrtf(x*x + y*y);
}
template <typename T>
T length(const vec2t<T> &v) {
	return sqrtf(v.x*v.x + v.y*v.y);
}

template <typename T>
vec2t<T> normalize(const vec2t<T> &v) {
	return v/length(v);
}

template <typename T>
T angle(const vec2t<T> &v) {
	return atan2f(v.y, v.x)*RAD2DEG;
}

// Dot product
template <typename T>
T dot(const vec2t<T> &a, const vec2t<T> &b) {
	return a.x*b.x + a.y*b.y;
}
