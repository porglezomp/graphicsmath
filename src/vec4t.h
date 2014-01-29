#ifndef GRAPHICSMATH_VEC_VEC4_H
#define GRAPHICSMATH_VEC_VEC4_H

template <typename T> struct vec3t;
template <typename T> struct vec2t;

template <typename T>
struct vec4t {
	T x, y, z, w;
// Constructors
	vec4t();
	vec4t(T);
	vec4t(T, T, T, T);
// Conversion constructors
	explicit vec4t(const vec3t<T>&);
	vec4t(const vec3t<T>&, T);
	vec4t(T, const vec3t<T>&);
	explicit vec4t(const vec2t<T>&);
	vec4t(const vec2t<T>&, T, T);
	vec4t(T, const vec2t<T>&, T);
	vec4t(T, T, const vec2t<T>&);
// Element indexing
	T& operator[] (const int);
// Arithmetic operators
	vec4t<T>& operator+= (const vec4t<T>&);
	vec4t<T>& operator-= (const vec4t<T>&);
	vec4t<T>& operator*= (const vec4t<T>&);
	vec4t<T>& operator*= (const T);
	vec4t<T>& operator/= (const vec4t<T>&);
	vec4t<T>& operator/= (const T);
	T length();
};

// Equality
template <typename T>
bool operator== (const vec4t<T>&, const vec4t<T>&);
template <typename T>
bool operator!= (const vec4t<T>&, const vec4t<T>&);

// Addition
template <typename T>
vec4t<T> operator+ (vec4t<T>, const vec4t<T>&);
template <typename T>
vec4t<T> operator+ (const vec4t<T>&, const vec3t<T>&);
template <typename T>
vec4t<T> operator+ (const vec3t<T>&, const vec4t<T>&);
template <typename T>
vec4t<T> operator+ (const vec4t<T>&, const vec2t<T>&);
template <typename T>
vec4t<T> operator+ (const vec2t<T>&, const vec4t<T>&);

// Subtraction
template <typename T>
vec4t<T> operator- (vec4t<T>, const vec4t<T>&);
template <typename T>
vec4t<T> operator- (const vec4t<T>&, const vec3t<T>&);
template <typename T>
vec4t<T> operator- (const vec3t<T>&, const vec4t<T>&);
template <typename T>
vec4t<T> operator- (const vec4t<T>&, const vec2t<T>&);
template <typename T>
vec4t<T> operator- (const vec2t<T>&, const vec4t<T>&);

// Negation
template <typename T>
vec4t<T> operator- (const vec4t<T>&);

// Componentwise vector multiplication
template <typename T>
vec4t<T> operator* (vec4t<T>, const vec4t<T>&);

// Scalar multiplication of the vector
template <typename T>
vec4t<T> operator* (vec4t<T>, const T);
template <typename T>
vec4t<T> operator* (const T, vec4t<T>);

// Componentwise vector division
template <typename T>
vec4t<T> operator/ (vec4t<T>, const vec4t<T>&);

// Scalar division of the vector
template <typename T>
vec4t<T> operator/ (vec4t<T>, const T);

// Length of the vector
template <typename T>
T length(const vec4t<T>&);

template <typename T>
vec4t<T> normalize(const vec4t<T>&);

//Dot product
template <typename T>
T dot(const vec4t<T>&, const vec4t<T>&);

#include "vec4t.cpp"
typedef vec4t<double> vec4d;
typedef vec4t<float> vec4f;
#ifdef GRAPHICSMATH_DEFAULT_DOUBLE
typedef vec4t<double> vec4;
#else
typedef vec4t<float> vec4;
#endif

#endif