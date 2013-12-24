#include "mat4.h"
#include "vec4.h"
#include <stdexcept>
#include <string>

// Constructors
mat4::mat4() : row1(0), row2(0), row3(0), row4(0) { }
mat4::mat4(vec4 a, vec4 b, vec4 c, vec4 d) :
			row1(a), row2(b), row3(c), row4(d) { }
mat4::mat4(float v[]) {
	for (int i = 0; i < 4; ++i) {
		(*this)[i] = vec4(v[i*4], v[i*4+1], v[i*4+2], v[i*4+3]);
	}
}

// Create an identity matrix
mat4 mat4::identity() {
	mat4 m;
	m.row1 = vec4(1, 0, 0, 0);
	m.row2 = vec4(0, 1, 0, 0);
	m.row3 = vec4(0, 0, 1, 0);
	m.row4 = vec4(0, 0, 0, 1);
	return m;
}

// Row indexing
vec4& mat4::operator[](const int i) {
	if (i == 0) return row1;
	if (i == 1) return row2;
	if (i == 2) return row3;
	if (i == 3) return row4;
	throw std::out_of_range(i + " out of range for mat4.");
}
