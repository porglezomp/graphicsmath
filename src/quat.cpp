#include "quat.h"

#include <stdio.h>
#include <math.h>
#include <string>
#include <stdexcept>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

#define PI 3.141592654
#define RAD2DEG 180/PI
#define DEG2RAD	PI/180

/* These quaternions are represented as
 * H = w + ix + jy + kz */

quat::quat() : x(0), y(0), z(0), w(1) { } // Identity Quaternion
quat::quat(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }
quat::quat(const vec3 &v, float s) : x(v.x), y(v.y), z(v.z), w(s) { }

float& quat::operator[] (const int i) {
	switch (i) {
		case 0: return x;
		case 1: return y;
		case 2: return z;
		case 3: return w;
	}
	char errnum[32];
	sprintf(errnum, "%i", i);
	throw std::out_of_range(errnum + std::string(" out of range on quat"));
}

quat angleAxis(float angle, const vec3 &axis) {
	angle *= DEG2RAD/2;
	float si = sin(angle);
	float co = cos(angle);
	vec3 ax = normalize(axis) * si;
	return quat(ax, co);
}

vec2 quat::rotate(const vec2 &v) {
	return vec2(this->rotate(vec3(v)));
}

vec3 quat::rotate(const vec3 &v) {
	quat p = quat(v, 0);
	quat q = *this;
	quat q_inv = quat(-q.x, -q.y, -q.z, q.w);
	p = q * p * q_inv;
	return vec3(p.x, p.y, p.z);
}

bool operator== (const quat &lhs, const quat &rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y &&
		   lhs.z == rhs.z && lhs.w == rhs.w;
}
bool operator!= (const quat &lhs, const quat &rhs) {
	return lhs.x != rhs.x || lhs.y != rhs.y ||
		   lhs.z != rhs.z || lhs.w != rhs.w;
}

quat operator* (const quat &a, const quat &b) {
	return quat(a.w*b.x + a.x*b.w + a.y*b.z - a.z*b.y,
		        a.w*b.y - a.x*b.z + a.y*b.w + a.z*b.x,
		        a.w*b.z + a.x*b.y - a.y*b.x + a.z*b.w,
		        a.w*b.w - a.x*b.x - a.y*b.y - a.z*b.z);
}