#ifndef GRAPHICSMATH_VEC_VEC4_H
#define GRAPHICSMATH_VEC_VEC4_H

struct vec4 {
	float x, y, z, w;
	vec4();
	vec4(float);
	vec4(float, float, float, float);
};

// Addition
vec4& vec4::operator+=(const vec4&);
vec4 operator+(vec4, const vec4&);

// Subtraction
vec4& vec4::operator-=(const vec4&);
vec4 operator-(vec4, const vec4&);

// Negation
vec4 vec4::operator-(const vec4&);

// Componentwise vector multiplication
vec4& vec4::operator*=(const vec4&);
vec4 operator*(vec4, const vec4&);

// Scalar multiplication of the vector
vec4& vec4::operator*=(const float);
vec4 operator*(vec4, const float);
vec4 operator*(const float, vec4);

// Componentwise vector division
vec4& vec4::operator/=(const vec4&);
vec4 operator/(vec4, const vec4&);

// Scalar division of the vector
vec4& vec4::operator/=(const float);
vec4 operator/(vec4, const float);
vec4 operator/(const float, vec4);

// Length of the vector
float vec4::length();
float length(const vec4&);

//Dot product
float dot(const vec4&, const vec4&);
#endif
