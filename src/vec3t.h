#ifndef GRAPHICSMATH_VEC_VEC3_H
#define GRAPHICSMATH_VEC_VEC3_H

//struct vec4;
template <typename T> struct vec2t;

template <typename T>
struct vec3t {
	T x, y, z;
// Constructors
	vec3t();
	vec3t(T);
	vec3t(T, T, T);
// Conversion constructors
	//explicit vec3t(const vec4&);
	vec3t(const vec2t<T>&);
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
struct vec3d;
struct vec3f : public vec3t<float> {
	vec3f() : vec3t<float>() { }
	vec3f(float x) : vec3t<float>(x) { }
	vec3f(float x, float y, float z) : vec3t<float>(x, y, z) { }
	vec3f(const vec2t<float> &v) : vec3t<float>(v) { }
	vec3f(const vec2t<float> &v, float z) : vec3t<float>(v, z) { }
	vec3f(float x, const vec2t<float> &v) : vec3t<float>(x, v) { }
	explicit vec3f(const vec3d&);
};

struct vec3d : public vec3t<double> {
	vec3d() : vec3t<double>() { }
	vec3d(double x) : vec3t<double>(x) { }
	vec3d(double x, double y, double z) : vec3t<double>(x, y, z) { }
	vec3d(const vec2t<double> &v) : vec3t<double>(v) { }
	vec3d(const vec2t<double> &v, double z) : vec3t<double>(v, z) { }
	vec3d(double x, const vec2t<double> &v) : vec3t<double>(x, v) { }
	vec3d(const vec3f &v) : vec3t<double>(v.x, v.y, v.z) { }
};

vec3f::vec3f(const vec3d &v) : vec3t<float>(v.x, v.y, v.z) { };

// Set a default type for vec3
#ifdef GRAPHICSMATH_DEFAULT_DOUBLE
typedef vec3d vec3;
#else // If not specified, float is the default
typedef vec3f vec3;
#endif

#endif