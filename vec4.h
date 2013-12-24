#ifndef GRAPHICSMATH_VEC_VEC4_H
#define GRAPHICSMATH_VEC_VEC4_H

struct vec4 {
	float x, y, z, w;
	vec4();
	vec4(float);
	vec4(float, float, float, float);
};

// Constructors
vec4::vec4() : x(0), y(0), z(0), w(0) { }
vec4::vec4(float v) : x(v), y(v), z(v), w(v) { }
vec4::vec4(float x, float y, float z, float w) :
			x(x), y(y), z(z), w(w) { }

// Addition
vec4 vec4::operator+=(const vec4&);
vec4 operator+(vec4, const vec4&);

// Subtraction
vec4 vec4::operator-=(const vec4&);
vec4 operator-(vec4, const vec4&);

// Negation
vec4 vec4::operator-(const vec4&);

// Componentwise vector multiplication
vec4 vec4::operator*=(const vec4&);
vec4 operator*(vec4, const vec4&);

// Scalar multiplication of the vector
vec4 vec4::operator*=(const float);
vec4 operator*(vec4, const float);
vec4 operator*(const float, vec4);

// Componentwise vector division
vec4 vec4::operator/=(const vec4&);
vec4 operator/(vec4, const vec4&);

// Scalar division of the vector
vec4 vec4::operator/=(const float);
vec4 operator/(vec4, const float);
vec4 operator/(const float, vec4);

float vec4::length();
float length(const vec4&);

#endif
