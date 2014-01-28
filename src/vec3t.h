#ifndef GRAPHICSMATH_VEC_VEC3_H
#define GRAPHICSMATH_VEC_VEC3_H

//struct vec4;
template <typename T> struct vec2t;

template <typename T>
class vec3t {
public:
	T x, y, z;
// Constructors
	vec3t();
	vec3t(T);
	vec3t(T, T, T);
	vec3t(const vec3t<T>&);
	template <typename U>
	explicit vec3t(const vec3t<U>&);
// Conversion constructors
	//explicit vec3t(const vec4&);
	template <typename U>
	explicit vec3t(const vec2t<U>&);
	vec3t(const vec2t<T>&, T);
	vec3t(T, const vec2t<T>&);
//Element indexing
	T& operator[] (const int);
// Arithmetic operators
	vec3t<T>& operator+= (const vec3t<T>&);
	vec3t<T>& operator-= (const vec3t<T>&);
	vec3t<T>& operator*= (const vec3t<T>&);
	vec3t<T>& operator*= (const T);
	vec3t<T>& operator/= (const vec3t<T>&);
	vec3t<T>& operator/= (const T);
	T length();
};

// Equality
template <typename T>
bool operator== (const vec3t<T>&, const vec3t<T>&);
template <typename T>
bool operator!= (const vec3t<T>&, const vec3t<T>&);

// Addition
template <typename T>
vec3t<T> operator+ (vec3t<T>, const vec3t<T>&);
template <typename T>
vec3t<T> operator+ (const vec3t<T>&, const vec2t<T>&);
template <typename T>
vec3t<T> operator+ (const vec2t<T>&, const vec3t<T>&);

// Subtraction
template <typename T>
vec3t<T> operator- (vec3t<T>, const vec3t<T>&);
template <typename T>
vec3t<T> operator- (const vec3t<T>&, const vec2t<T>&);
template <typename T>
vec3t<T> operator- (const vec2t<T>&, const vec3t<T>&);

// Negation
template <typename T>
vec3t<T> operator- (const vec3t<T>&);

// Componentwise vector multiplication
template <typename T>
vec3t<T> operator* (vec3t<T>, const vec3t<T>&);

// Scalar multiplication of the vector
template <typename T>
vec3t<T> operator* (vec3t<T>, const T);
template <typename T>
vec3t<T> operator* (const T, vec3t<T>);

// Componentwise vector division
template <typename T>
vec3t<T> operator/ (vec3t<T>, const vec3t<T>&);

// Scalar division of the vector
template <typename T>
vec3t<T> operator/ (vec3t<T>, const T);

// Length of the vector
template <typename T>
T length(const vec3t<T>&);

template <typename T>
vec3t<T> normalize(const vec3t<T>&);

//Dot product
template <typename T>
T dot(const vec3t<T>&, const vec3t<T>&);

/// Cross product
template <typename T>
vec3t<T> cross(const vec3t<T>&, const vec3t<T>&);

#include "vec3t.cpp"
typedef vec3t<double> vec3d;
typedef vec3t<float> vec3f;
#ifdef GRAPHICSMATH_DEFAULT_DOUBLE
typedef vec3t<double> vec3;
#else
typedef vec3t<float> vec3;
#endif

#endif
