#ifndef GRAPHICSMATH_MAT_MAT4_H
#define GRPAHICSMATH_MAT_MAT4_H

#include "vec4.h"

struct mat4 {
	vec4 row1, row2, row3, row4;
	mat4();
	mat4(vec4, vec4, vec4, vec4);
	mat4(float[]);
	mat4 identity();
	vec4& operator[](const int i);
	mat4& operator+= (const mat4&);
	mat4& operator-= (const mat4&);
	mat4& operator*= (const mat4&);
	//mat4& rotate(float, float, float, float);
	mat4& translate(float, float, float);
	mat4& scale(float, float, float);
};

mat4 operator+ (mat4, const mat4&);
mat4 operator- (mat4, const mat4&);
vec4 operator* (vec4, const mat4&);
vec4 operator* (const mat4&, const vec4&);
mat4 transpose(const mat4&);
//mat4 mat4rotation(float, float, float, float);
mat4 mat4translation(float, float, float);
mat4 mat4scale(float, float, float);

#endif
