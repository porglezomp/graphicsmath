#ifndef GRAPHICSMATH_QUAT_H_
#define GRAPHICSMATH_QUAT_H_

struct vec2;
struct vec3;
struct vec4;

/* These quaternions are represented as
 * H = w + ix + jy + kz */

struct quat {
	float x, y, z, w;

	quat(); // Identity Quaternion
	quat(float, float, float, float);
	quat(const vec3&, float);

	float& operator[] (const int);
	vec2 rotate(const vec2&);
	vec3 rotate(const vec3&);
};

quat angleAxis(float, const vec3&);
bool operator== (const quat&, const quat&);
quat operator* (const quat&, const quat&);

#endif