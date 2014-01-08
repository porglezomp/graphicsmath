## Process this file with automake to produce Makefile.in

LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

AM_CPPFLAGS=-I$(top_builddir)/src
vecsrc = ../src/vec2.cpp ../src/vec3.cpp ../src/vec4.cpp
matsrc = ../src/mat4.cpp ../src/mat2.cpp
libsrc = $(vecsrc) $(matsrc)
## Test suite
check_PROGRAMS = Vec2Test.exe Vec3Test.exe Vec4Test.exe Mat2Test.exe Mat4Test.exe

Vec2Test_exe_SOURCES = vec2test.cpp $(vecsrc)
Vec3Test_exe_SOURCES = vec3test.cpp $(vecsrc)
Vec4Test_exe_SOURCES = vec4test.cpp $(vecsrc)
Mat2Test_exe_SOURCES = mat2test.cpp ../src/vec2.cpp ../src/mat2.cpp
Mat4Test_exe_SOURCES = mat4test.cpp ../src/vec4.cpp ../src/mat4.cpp
TESTS = $(check_PROGRAMS)
EXTRA_DIST = $(TESTS)
