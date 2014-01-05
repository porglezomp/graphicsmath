#ifndef GRAPHICSMATH_VEC_VEC3_H
#define GRAPHICSMATH_VEC_VEC3_H

struct vec3 {
	float x, y, z;
// Constructors
	vec3();
	vec3(float);
	vec3(float, float, float);
// Conversion constructors
	vec3(const vec4&);
	vec3(const vec2&);
	vec3(const vec2&, float);
	vec3(float, const vec2&);
//Element indexing
	float& operator[](const int);
// Arithmetic operators
	vec3& operator+=(const vec3&);
	vec3& operator-=(const vec3&);
	vec3& operator*=(const vec3&);
	vec3& operator*=(const float);
	vec3& operator/=(const vec3&);
	vec3& operator/=(const float);
// Negation
	vec3 operator-(const vec3&);
	float length();
};

// Equality
bool operator==(const vec3&, const vec3&);
bool operator!=(const vec3&, const vec3&);

// Addition
vec3 operator+(vec3, const vec3&);
vec3 operator+ (const vec3&, const vec2&);
vec3 operator+ (const vec2&, const vec3&);

// Subtraction
vec3 operator-(vec3, const vec3&);
vec3 operator- (const vec3&, const vec2&);
vec3 operator- (const vec2&, const vec3&);

// Componentwise vector multiplication
vec3 operator*(vec3, const vec3&);

// Scalar multiplication of the vector
vec3 operator*(vec3, const float);
vec3 operator*(const float, vec3);

// Componentwise vector division
vec3 operator/(vec3, const vec3&);

// Scalar division of the vector
vec3 operator/(vec3, const float);
vec3 operator/(const float, vec3);

// Length of the vector
float length(const vec3&);

//Dot product
float dot(const vec3&, const vec3&);

#endif
