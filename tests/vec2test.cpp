#include "vec2template.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	puts("1..14"); //Show the test plan

	if (vec2(0) != vec2(0)) puts("Bail out! 1 - != inequality doesn't function");
	else puts("ok 1 - basic inequality works");
	if (vec2(0) == vec2(1)) puts("Bail out! 2 - == equality doesn't function");
	else puts("ok 2 - basic equality works");
	if (vec2(5, 2) != vec2(5, 2)) puts("not ok 3 - two component inequality is broken");
	else puts("ok 3 - two component inequality works");
	if (vec2(3, 7) == vec2(1, 6)) puts("not ok 4 - two component equality is broken");
	else puts("ok 4 - two component equality works");
	if (vec2() != vec2(0)) puts("not ok 5 - empty constructor doesn't produce the zero vector");
	else puts("ok 5 - empty constructor produces the zero vector");
	if (vec2(0) != vec2(0, 0)) puts("not ok 6 - setting one component doesn't set both (tested for 0)");
	else puts("ok 6 - setting one component sets both correctly (tested for 0)");
	if (vec2(135) != vec2(135, 135)) puts("not ok 7 - (tested for 135)");
	else puts("ok 7 - (tested for 135)");
	vec2 a, b, c;
	a = vec2(12, 14);
	if (a.x != 12 || a.y != 14) puts("not ok 8 - vec2(x, y) constructor failed");
	else puts("ok 8 - vec2(x, y) constructor");

	a = 0; b = 1; c = 1;
	if (a + b != c) puts("not ok 9 - simple vector addition failed");
	else puts("ok 9 - simple vector addition");
	a = vec2(0, 1);
	b = vec2(4, 5);
	c = vec2(4, 6);
	if (a + b != c) puts("not ok 10 - vector addition failed");
	else puts("ok 10 - vector addition");
	c = vec2(-4);
	if (a - b != c) puts("not ok 11 - vector subtraction failed");
	else puts("ok 11 - vector subtraction");
	a = vec2(2, 0);
	if (normalize(a) != vec2(1, 0)) puts("not ok 12 - basic normalize() failed");
	else puts("ok 12 - basic normalize");
	if (normalize(vec2(1)) != vec2(1/sqrtf(2))) puts("not ok 13 - normalize() failed");
	else puts("ok 13 - normalize");
	if (angle(vec2(1)) != 45) puts("not ok 14 - angle() failed");
	else puts("ok 14 - angle()");
	return 0;
}

/*
bool operator== (const vec2&, const vec2&);
bool operator!= (const vec2&, const vec2&);
struct vec2 {
	float x, y;
// Constructors
	vec2();
	vec2(float);
	vec2(float, float);
// Conversion constructors
	explicit vec2(const vec4&);
	explicit vec2(const vec3&);
// Element indexing
	float& operator[] (const int);
// Arithmetic operators
	vec2& operator+= (const vec2&);
	vec2& operator-= (const vec2&);
	vec2& operator*= (const vec2&);
	vec2& operator*= (const float);
	vec2& operator/= (const vec2&);
	vec2& operator/= (const float);
	vec2& operator*= (const mat2&);
	float length();
};
vec2 operator+ (vec2, const vec2&);
vec2 operator- (vec2, const vec2&);
vec2 operator- (const vec2&);
vec2 operator* (vec2, const vec2&);
vec2 operator* (vec2, const float);
vec2 operator* (const float, vec2);
vec2 operator/ (vec2, const vec2&);
vec2 operator/ (vec2, const float);
vec2 operator/ (const float, vec2);
float length(const vec2&);
float dot(const vec2&, const vec2&);
*/
