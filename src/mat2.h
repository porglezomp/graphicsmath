#ifndef GRAPHICSMATH_MAT_MAT2_H
#define GRPAHICSMATH_MAT_MAT2_H

#include "vec2.h"

struct mat2 {
	vec2 col1, col2;
	mat2();
	mat2(vec2, vec2);
	mat2(float[]);
	static mat2 identity();
	mat2& operator+= (const mat2&);
	mat2& operator-= (const mat2&);
	mat2& operator*= (const mat2&);
	mat2& operator*= (const float);
	//mat2& rotate(float);
	mat2& scale(float, float);
};

mat2 operator+ (mat2, const mat2&);
mat2 operator- (mat2, const mat2&);
mat2 operator* (mat2, const float);
vec2 operator* (vec2, mat2&);
vec2 operator* (mat2&, const vec2&);
vec2 operator* (mat2&, mat2&);
mat2 transpose(const mat2&);
mat2 invert(const mat2&);
//mat2 mat2rotation(float);
mat2 mat2scale(float, float);
float det(const mat2&);
#endif
