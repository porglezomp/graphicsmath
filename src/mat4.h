#ifndef GRAPHICSMATH_MAT_MAT4_H_
#define GRAPHICSMATH_MAT_MAT4_H_

#include "vec4.h"

struct mat4 {
	vec4 col1, col2, col3, col4;
	mat4();
	mat4(vec4, vec4, vec4, vec4);
	//mat4(float[]);
	static mat4 identity();
	vec4& operator[] (const int i);
	mat4& operator+= (const mat4&);
	mat4& operator-= (const mat4&);
	mat4& operator*= (const mat4&);
	mat4& operator*= (const float);
	mat4& rotate(float, const vec3&);
	mat4& translate(float, float, float);
	mat4& scale(float, float, float);
	vec4 getRow(const int) const;
	vec4 getCol(const int) const;
	void setRow(const int, const vec4&);
	void setCol(const int, const vec4&);
	static mat4 rotationmatrix(float, const vec3&);
	static mat4 translationmatrix(float, float, float);
	static mat4 scalematrix(float, float, float);
};

bool operator== (const mat4&, const mat4&);
bool operator!= (const mat4&, const mat4&);
mat4 operator+ (mat4, const mat4&);
mat4 operator- (mat4, const mat4&);
vec4 operator* (const vec4&, const mat4&);
vec4 operator* (const mat4&, const vec4&);
mat4 operator* (mat4, const mat4&);
mat4 operator* (mat4&, const float);
mat4 operator* (const float, mat4&);
mat4 transpose(const mat4&);
mat4 invert(const mat4&);
float det(const mat4&);

#endif
