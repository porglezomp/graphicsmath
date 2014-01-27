## Process this file with automake to produce Makefile.in

LOG_DRIVER = env AM_TAP_AWK='$(AWK)' $(SHELL) \
                  $(top_srcdir)/build-aux/tap-driver.sh

AM_CPPFLAGS=-I$(top_builddir)/src
## Test suite
LDADD = ../src/libgraphicsmath0.a
check_PROGRAMS = Vec2Test.exe Vec3Test.exe Vec4Test.exe Mat2Test.exe Mat3Test.exe Mat4Test.exe

Vec2Test_exe_SOURCES = vec2test.cpp
Vec3Test_exe_SOURCES = vec3test.cpp 
Vec4Test_exe_SOURCES = vec4test.cpp 
Mat2Test_exe_SOURCES = mat2test.cpp 
Mat3Test_exe_SOURCES = mat3test.cpp
Mat4Test_exe_SOURCES = mat4test.cpp
TESTS = $(check_PROGRAMS)
EXTRA_DIST = $(TESTS)
