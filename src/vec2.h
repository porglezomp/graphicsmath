#ifndef GRAPHICSMATH_VEC_VEC2_H
#define GRAPHICSMATH_VEC_VEC2_H

struct vec2 {
	float x, y;
// Constructors
	vec2();
	vec2(float);
	vec2(float, float);
// Conversion constructors
	vec2(const vec4&);
	vec2(const vec3&);
// Element indexing
	float& operator[](const int);
// Arithmetic operators
	vec2& operator+=(const vec2&);
	vec2& operator-=(const vec2&);
	vec2& operator*=(const vec2&);
	vec2& operator*=(const float);
	vec2& operator/=(const vec2&);
	vec2& operator/=(const float);
// Negation
	vec2 operator-(const vec2&);
	float length();
};

// Equality
bool operator==(const vec2&, const vec2&);
bool operator!=(const vec2&, const vec2&);

// Addition
vec2 operator+(vec2, const vec2&);

// Subtraction
vec2 operator-(vec2, const vec2&);

// Componentwise vector multiplication
vec2 operator*(vec2, const vec2&);

// Scalar multiplication of the vector
vec2 operator*(vec2, const float);
vec2 operator*(const float, vec2);

// Componentwise vector division
vec2 operator/(vec2, const vec2&);

// Scalar division of the vector
vec2 operator/(vec2, const float);
vec2 operator/(const float, vec2);

// Length of the vector
float length(const vec2&);

//Dot product
float dot(const vec2&, const vec2&);

#endif
