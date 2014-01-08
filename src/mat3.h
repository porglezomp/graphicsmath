#ifndef GRAPHICSMATH_MAT_mat3_H
#define GRPAHICSMATH_MAT_mat3_H

#include "vec3.h"

struct mat3 {
	vec3 col1, col2, col3;
	mat3();
	mat3(vec3, vec3, vec3);
	//mat3(float[]);
	static mat3 identity();
	vec3& operator[] (const int i);
	mat3& operator+= (const mat3&);
	mat3& operator-= (const mat3&);
	mat3& operator*= (const mat3&);
	//mat3& rotate(float, float, float, float);
	mat3& translate(float, float);
	mat3& scale(float, float, float);
};

mat3 operator+ (mat3, const mat3&);
mat3 operator- (mat3, const mat3&);
vec3 operator* (vec3, mat3&);
vec3 operator* (mat3&, const vec3&);
vec3 operator* (mat3&, mat3&);
mat3 transpose(const mat3&);
//mat3 mat3rotation(float, float, float, float);
//mat3 mat3rotation(float);
mat3 mat3translation(float, float);
mat3 mat3scale(float, float, float);

#endif