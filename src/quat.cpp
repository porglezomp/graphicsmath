#include "quat.h"

#include <stdio.h>
#include <string>
#include <stdexcept>
#include "vec2.h"
#include "vec3.h"
#include "vec4.h"

quat::quat() : x(1), y(0), z(0), w(0) { } // Identity Quaternion
quat::quat(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) { }

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
// TODO: Implement
quat angleAxis(float angle, const vec3 &axis) {
	return quat();
}
// TODO: Implement
vec2 rotate(const vec2 &v) {
	return v;
}
// TODO: Implement
vec3 rotate(const vec3 &v) {
	return v;
}
// TODO: Implement
vec4 rotate(const vec4 &v) {
	return v;
}

bool operator== (const quat &lhs, const quat &rhs) {
	return lhs.x == rhs.x && lhs.y == rhs.y &&
		   lhs.z == rhs.z && lhs.w == rhs.w;
}
bool operator!= (const quat &lhs, const quat &rhs) {
	return lhs.x != rhs.x || lhs.y != rhs.y ||
		   lhs.z != rhs.z || lhs.w != rhs.w;
}

// TODO: Implement
quat operator* (const quat &a, const quat &b) {
	return a;
}