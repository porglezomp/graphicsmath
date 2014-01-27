#ifndef GRAPHICSMATH_MAT_MAT3_H
#define GRPAHICSMATH_MAT_MAT3_H

#include "vec3.h"
#include "vec2.h"

struct mat3 {
	vec3 col1, col2, col3;
	mat3();
	mat3(vec3, vec3, vec3);
	mat3(float[]);
	static mat3 identity();
	vec3& operator[] (const int i);
	mat3& operator+= (const mat3&);
	mat3& operator-= (const mat3&);
	mat3& operator*= (const mat3&);
	mat3& rotate(float, const vec3&);
	mat3& rotate(float);
	mat3& translate(float, float);
	mat3& scale(float, float, float);
	vec3 row(const int) const;
	vec3 col(const int) const;
	static mat3 rotationmatrix(float);
	static mat3 rotationmatrix(float, const vec3&);
	static mat3 translationmatrix(float, float);
	static mat3 scalematrix(float, float, float);
};

bool operator== (const mat3&, const mat3&);
bool operator!= (const mat3&, const mat3&);
mat3 operator+ (mat3, const mat3&);
mat3 operator- (mat3, const mat3&);
vec3 operator* (const vec3&, const mat3&);
vec3 operator* (const mat3&, const vec3&);
vec2 operator* (const vec2&, const mat3&);
vec2 operator* (const mat3&, const vec2&);
mat3 operator* (mat3, const mat3&);
mat3 transpose(const mat3&);

#endif
