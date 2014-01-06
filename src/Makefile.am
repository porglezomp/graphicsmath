## Process this file with automake to produce Makefile.in

lib_LIBRARIES = libgraphicsmath-0.0.a

## Use a seperate line here so I don't have to retype that huge thing so many times down below
libsrc = vec2.cpp vec3.cpp vec4.cpp
libgraphicsmath_0_0_a_SOURCES = $(libsrc)
library_includedir = $(includedir)/graphicsmath0/
library_include_HEADERS = vec2.h vec3.h vec4.h

## Test suite
check_PROGRAMS = tests/Vec2Test.exe tests/Vec3Test.exe tests/Vec4Test.exe
tests_Vec2Test_exe_SOURCES = tests/vec2test.cpp $(libsrc)
tests_Vec3Test_exe_SOURCES = tests/vec3test.cpp $(libsrc)
tests_Vec4Test_exe_SOURCES = tests/vec4test.cpp $(libsrc)
TESTS = $(check_PROGRAMS)
