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
};

#endif
