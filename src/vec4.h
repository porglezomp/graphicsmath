#ifndef GRAPHICSMATH_VEC_VEC4_H
#define GRAPHICSMATH_VEC_VEC4_H

struct vec3;
struct vec2;

struct vec4 {
	float x, y, z, w;
// Constructors
	vec4();
	vec4(float);
	vec4(float, float, float, float);
// Conversion constructors
	explicit vec4(const vec3&);
	vec4(const vec3&, float);
	vec4(float, const vec3&);
	explicit vec4(const vec2&);
	vec4(const vec2&, float, float);
	vec4(float, const vec2&, float);
	vec4(float, float, const vec2&);
// Element indexing
	float& operator[] (const int);
// Arithmetic operators
	vec4& operator+= (const vec4&);
	vec4& operator-= (const vec4&);
	vec4& operator*= (const vec4&);
	vec4& operator*= (const float);
	vec4& operator/= (const vec4&);
	vec4& operator/= (const float);
	float length();
};

// Equality
bool operator== (const vec4&, const vec4&);
bool operator!= (const vec4&, const vec4&);

// Addition
vec4 operator+ (vec4, const vec4&);
vec4 operator+ (const vec4&, const vec3&);
vec4 operator+ (const vec3&, const vec4&);
vec4 operator+ (const vec4&, const vec2&);
vec4 operator+ (const vec2&, const vec4&);

// Subtraction
vec4 operator- (vec4, const vec4&);
vec4 operator- (const vec4&, const vec3&);
vec4 operator- (const vec3&, const vec4&);
vec4 operator- (const vec4&, const vec2&);
vec4 operator- (const vec2&, const vec4&);

// Negation
vec4 operator- (const vec4&);

// Componentwise vector multiplication
vec4 operator* (vec4, const vec4&);

// Scalar multiplication of the vector
vec4 operator* (vec4, const float);
vec4 operator* (const float, vec4);

// Componentwise vector division
vec4 operator/ (vec4, const vec4&);

// Scalar division of the vector
vec4 operator/ (vec4, const float);

// Length of the vector
float length(const vec4&);

vec4 normalize(const vec4&);

//Dot product
float dot(const vec4&, const vec4&);

#endif
