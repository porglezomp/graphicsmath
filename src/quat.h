#ifndef GRAPHICSMATH_QUAT_H_
#define GRAPHICSMATH_QUAT_H_

struct vec2;
struct vec3;
struct vec4;

struct quat {
	float x, y, z, w;

	quat(); // Identity Quaternion
	quat(float, float, float, float);

	float& operator[] (const int);
	quat angleAxis(float, const vec3&);
	vec2 rotate(const vec2&);
	vec3 rotate(const vec3&);
	vec4 rotate(const vec4&);
};

bool operator== (const quat&, const quat&);
quat operator* (const quat&, const quat&);

#endif